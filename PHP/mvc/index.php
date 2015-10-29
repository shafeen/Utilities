<?php


/*
 * This is the main application FrontController
 *
 * The first parameter decides which module's FrontController to call.
 * From there, the module's FrontController dispatches to individual
 * page Controllers.
 *
 */


function getRequestUrlPathParamArray() {
    $explodedPath = explode("/", $_SERVER["REQUEST_URI"]);
    $cleanExplodedPath = array();
    foreach ($explodedPath as $pathVar) {
        if (!empty($pathVar)) {
            $cleanExplodedPath[] = $pathVar;
        }
    }
    return $cleanExplodedPath;
}


// parse the url for the module to run
// expected path format = {serverroot}/app/{moduleName}
$reqPathParamArray = getRequestUrlPathParamArray();
print_r($reqPathParamArray);


