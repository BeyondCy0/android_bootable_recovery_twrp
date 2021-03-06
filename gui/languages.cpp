#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/reboot.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <time.h>
#include <unistd.h>

#include <string>

extern "C" {
#include "../common.h"
#include "../minuitwrp/minui.h"
#include "../recovery_ui.h"

#include "../minzip/SysUtil.h" //for MemMapping struct ;
#include "../minzip/Zip.h"
}

#include "rapidxml.hpp"
#include "objects.hpp"

xml_document<> lang;

std::string LanguageManager::parse(std::string id)
{
	for(xml_node<>* root_node = lang.first_node("Languages"); root_node; root_node = root_node->next_sibling())
	{
		std::string lang_name;
		DataManager::GetValue("tw_lang_name", lang_name);
		//LOGINFO("tw_lang_name = %s \n",lang_name.c_str());
		if (lang_name == root_node->first_attribute("Language")->value())
		{
			for(xml_node<> * string_node = root_node->first_node("string"); string_node; string_node = string_node->next_sibling())
			{
				xml_attribute<>* attr = string_node->first_attribute("id");
				if (id == attr->value())
					return string_node->value();
			}
		}
	}
	return "";
}

void Load(char* xmlFile)
{
	lang.parse<0>(xmlFile);
}

int LanguageManager::LoadLanguages(std::string package)
{
    int fd;
    ZipArchive zip, *pZip = NULL;
    long len;
    char* xmlFile = NULL;
    MemMapping map;

	DataManager::ReadSettingsFile();
	std::string lang_path = "/res/languages.xml";

    //Map the LanguagePackage into memory
    if (sysMapFile(package.c_str(),&map) != 0) {
        LOGE("Failed to map languagepackage into file\n");
        return -1;
    }


    // Open the XML file

    if (mzOpenZipArchive(map.addr,map.length, &zip))
    {
		LOGI("Loading language xml %s\n", lang_path.c_str());
        // We can try to load the XML directly...
        struct stat st;
        if(stat(lang_path.c_str(),&st) != 0) {
            sysReleaseMap(&map);
            return -1;
        }

        len = st.st_size;
        xmlFile = (char*) malloc(len + 1);
        if (!xmlFile)       return -1;

        fd = open(lang_path.c_str(), O_RDONLY);
        if (fd == -1)       goto error;

        read(fd, xmlFile, len);
        close(fd);
    }
    else
    {
		LOGI("Loading language xml %s from package: %s\n", lang_path.c_str(), package.c_str());
        pZip = &zip;
        const ZipEntry* ui_xml = mzFindZipEntry(&zip, lang_path.c_str());
        if (ui_xml == NULL)
        {
            LOGE("Unable to locate %s in zip file\n", lang_path.c_str());
            goto error;
        }

        // Allocate the buffer for the file
        len = mzGetZipEntryUncompLen(ui_xml);
        xmlFile = (char*) malloc(len + 1);
        if (!xmlFile)        goto error;
    
        if (!mzExtractZipEntryToBuffer(&zip, ui_xml, (unsigned char*) xmlFile))
        {
            LOGE("Unable to extract %s\n", lang_path.c_str());
            goto error;
        }
    }

    // NULL-terminate the string
    xmlFile[len] = 0x00;

    Load(xmlFile);

    if (pZip)   mzCloseZipArchive(pZip);
    return 0;

error:
//    LOGE("An internal error has occurred.\n");
    if (pZip)       mzCloseZipArchive(pZip);
    if (xmlFile)    free(xmlFile);
    return -1;
}
