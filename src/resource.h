#pragma once

#include "pch.h"
#include <string>
#include <map>

enum ResourceType
{
	k_Bitmap,
	k_Sound,
};

class Resource
{
public:
	Resource(const std::wstring& file_name, const std::string& resource_name, ResourceType resource_type);

	template<typename T>
	static T* GetResource(const std::string& resource_name);

private:
	std::string m_resource_name;
	std::wstring m_resource_path;
	ResourceType m_resource_type;

private:
	static std::map<std::string, Resource*> s_resources_set;

};

class ImageResource : Resource
{
public:
	ImageResource(const std::wstring& file_name, const std::string& resource_name);
	Gdiplus::Image* get_image() { return m_image; }

private:
	Gdiplus::Image* m_image = nullptr;

};

template<typename T>
inline T * Resource::GetResource(const std::string & resource_name)
{
	return (T*)(s_resources_set[resource_name]);
}
