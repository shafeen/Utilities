<?php


/*
 * This is the main application FrontController
 *
 * The first parameter decides which module's FrontController to call.
 * From there, the module's FrontController dispatches to individual
 * page Controllers.
 *
 */

use framework\components\CleanRequestUrlParser;
require_once("components/CleanRequestUrlParser.php");

function initAndIncludeView() {
    // parse the url for the module to run
    // expected path format = {serverroot}/app/{moduleName}
    $reqPathParamArray = CleanRequestUrlParser::instance()->getExplodedCleanRequestUrl();
    //print_r($reqPathParamArray);

    // need to define the location for our used components
    $jQueryPath = "./bower_components/jquery/dist/jquery.min.js";
    $bootstrapCssPath = "./bower_components/bootstrap/dist/css/bootstrap.min.css";
    $bootstrapOptionalThemeCssPath = "./bower_components/bootstrap/dist/css/bootstrap-theme.min.css";
    $bootstrapJavascriptPath = "./bower_components/bootstrap/dist/js/bootstrap.min.js";
    include("views/html/index.phtml");
}

initAndIncludeView();
