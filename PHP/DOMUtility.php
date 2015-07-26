<?php
/**
 * User: Shafeen M.
 * Date: 4/24/2015
 * Time: 10:53 AM
 */

class DOMUtility
{
    // return all attributes of a domNode as array($key => $value)
    public static function getDomNodeAttributeMap($domNode)
    {
        $attrMap = array();
        for($i = 0; $i < $domNode->attributes->length; $i++) {
            $domNodeAttr = $domNode->attributes->item($i);
            $attrMap[$domNodeAttr->name] = $domNodeAttr->value;
        }
        return $attrMap;
    }


    // if attribute does not exist -> return empty string
    public static function getDomNodeAttributeValue($domNode, $attribute='class')
    {
        $numAttributes = $domNode->attributes->length;
        for($i = 0; $i < $numAttributes; $i++) {
            $domNodeAttr = $domNode->attributes->item($i);
            if($domNodeAttr->name == $attribute) {
                return $domNodeAttr->value;
            }
        }
        return '';
    }

    // get all the html/xml contents of the domNode
    public static function getDomNodeXmlStr($domNode)
    {
        return $domNode->ownerDocument->saveXML($domNode);
    }

    private static function isRelativeLink($linkStr)
    {
        return (substr($linkStr, 0, 1)=='/')? true : false;
    }


    // parse all links <a href="..."> within the xml string provided
    // relative links should be assumed to be relative to the $websiteRoot
    public static function parseLinks($xmlStr, $websiteRoot)
    {
        $links = array();
        $regexp = "<a\s[^>]*href=(\"??)([^\" >]*?)\\1[^>]*>(.*)<\/a>";
        if(preg_match_all("/$regexp/siU", $xmlStr, $matches)) {
            $linkAddressList = $matches[2];
            // $matches[3] = array of link text - including HTML code
            foreach($linkAddressList as $link) {
                $link = (DOMUtility::isRelativeLink($link))? $websiteRoot.$link : $link;
                array_push($links, $link);
            }
        }
        return $links;
    }

    // Utility class ONLY, cannot instantiate
    private function __construct()
    {}

}
