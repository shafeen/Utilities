<?php

namespace framework\views;

abstract class ModuleView
{
    // $mainHtmlFile should take care and only access
    // variables through the ModelView class that "include"s it
    protected $mainHtmlFile;

    function __construct(&$model) {
        $this->extractInfoFromModel($model);
    }

    /** @param string $filename */
    function setMainHtmlFile($filename) {
        $this->mainHtmlFile = $filename;
    }

    abstract protected function extractInfoFromModel(&$model);

    function displayContent() {
        include("views/html/".$this->mainHtmlFile);
    }

}