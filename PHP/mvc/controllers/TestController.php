<?php
/**
 * Created by IntelliJ IDEA.
 * User: SHAFEEEENZZ
 * Date: 11/7/15
 * Time: 12:25 AM
 */

namespace framework\controllers;

require_once("controllers/ModuleController.php");

class TestController extends ModuleController
{
    function run() {
        // parse the url for the module to run
        // expected path format = {serverroot}/app/{moduleName}
        $reqPathParamArray = $this->explodedPathToModule;
        //print_r($reqPathParamArray);

        // need to define the location for our used components
        $jQueryPath = "bower_components/jquery/dist/jquery.min.js";
        $bootstrapCssPath = "bower_components/bootstrap/dist/css/bootstrap.min.css";
        $bootstrapOptionalThemeCssPath = "bower_components/bootstrap/dist/css/bootstrap-theme.min.css";
        $bootstrapJavascriptPath = "bower_components/bootstrap/dist/js/bootstrap.min.js";
        include("views/html/index.phtml");
    }

}