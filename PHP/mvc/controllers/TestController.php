<?php

namespace framework\controllers;

use framework\controllers\ModuleController;
require_once("controllers/ModuleController.php");

use framework\views\TestView;
require_once("views/TestView.php");

class TestController extends ModuleController
{
    function run() {
        $emptyModel = array("reqPathParamArray" => $this->explodedPathToModule);
        $this->moduleView = new TestView($emptyModel);
        $this->moduleView->setMainHtmlFile("index.phtml");
        $this->moduleView->displayContent();
    }

}