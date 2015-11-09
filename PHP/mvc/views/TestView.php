<?php

namespace framework\views;

use framework\views\ModuleView;
require_once("views/ModuleView.php");

class TestView extends ModuleView {

    protected function extractInfoFromModel(&$model) {
        // parse the url for the module to run
        // expected path format = {serverroot}/app/{module
        $this->reqPathParamArray = $model["reqPathParamArray"];

        // need to define the location for our used components
        $this->jQueryPath = "bower_components/jquery/dist/jquery.min.js";
        $this->bootstrapCssPath = "bower_components/bootstrap/dist/css/bootstrap.min.css";
        $this->bootstrapOptionalThemeCssPath = "bower_components/bootstrap/dist/css/bootstrap-theme.min.css";
        $this->bootstrapJavascriptPath = "bower_components/bootstrap/dist/js/bootstrap.min.js";
    }

}