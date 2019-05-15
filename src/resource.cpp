#include "resource.h"

std::map<std::string, Resource*> Resource::s_resources_set;

Resource::Resource(const std::wstring & file_name, const std::string& resource_name, ResourceType resource_type)
	:m_resource_path(file_name)
	, m_resource_name(resource_name)
	, m_resource_type(resource_type)
{
	s_resources_set[resource_name] = this;
}

ImageResource::ImageResource(const std::wstring & file_name, const std::string& resource_name)
	:
	Resource(file_name, resource_name, ResourceType::k_Bitmap)
{
	m_image = new Gdiplus::Image(file_name.data());
}
