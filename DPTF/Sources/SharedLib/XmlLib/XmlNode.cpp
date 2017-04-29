/******************************************************************************
** Copyright (c) 2013-2017 Intel Corporation All Rights Reserved
**
** Licensed under the Apache License, Version 2.0 (the "License"); you may not
** use this file except in compliance with the License.
**
** You may obtain a copy of the License at
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
** WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
**
** See the License for the specific language governing permissions and
** limitations under the License.
**
******************************************************************************/

#include "XmlNode.h"
#include "XmlGeneratorFactory.h"

XmlNode::XmlNode(NodeType::Type type, std::string rootXmlTag)
	: m_type(type)
	, m_rootXmlTag(rootXmlTag)
	, m_data("")
{
}

XmlNode::XmlNode(NodeType::Type type, std::string rootXmlTag, std::string data)
	: m_type(type)
	, m_rootXmlTag(rootXmlTag)
	, m_data(data)
{
}

XmlNode::~XmlNode(void)
{
}

std::shared_ptr<XmlNode> XmlNode::createRoot()
{
	return std::make_shared<XmlNode>(XmlNode(NodeType::Root, ""));
}

std::shared_ptr<XmlNode> XmlNode::createComment(std::string comment)
{
	return std::make_shared<XmlNode>(XmlNode(NodeType::Comment, "", std::string(" ") + comment + std::string(" ")));
}

std::shared_ptr<XmlNode> XmlNode::createWrapperElement(std::string tagName)
{
	return std::make_shared<XmlNode>(XmlNode(NodeType::Element, tagName));
}

std::shared_ptr<XmlNode> XmlNode::createDataElement(std::string tagName, std::string data)
{
	return std::make_shared<XmlNode>(XmlNode(NodeType::Element, tagName, data));
}

void XmlNode::addChild(std::shared_ptr<XmlNode> child)
{
	m_children.push_back(child);
}

void XmlNode::addAttribute(std::string attribute)
{
	m_attributes.push_back(attribute);
}

std::vector<std::shared_ptr<XmlNode>> XmlNode::getChildren()
{
	return m_children;
}

std::vector<std::string> XmlNode::getAttributes()
{
	return m_attributes;
}

NodeType::Type XmlNode::getNodeType()
{
	return m_type;
}

std::string XmlNode::getXmlTag()
{
	return m_rootXmlTag;
}

std::string XmlNode::getData()
{
	return m_data;
}

std::string XmlNode::toString()
{
	XmlGeneratorFactoryInterface* factory = new XmlGeneratorFactory();
	XmlGeneratorInterface* xmlGenerator = factory->createXmlGeneratorObject(1);

	xmlGenerator->addNode(this);

	std::string s = xmlGenerator->toString();

	delete xmlGenerator;
	delete factory;

	return s;
}
