<?php

/**
 * Created by Shafeen M.
 * Date: 11/2/2015
 */
class CleanRequestUrlParser
{
    static private $instance;

    private $explodedCleanRequestUrl;

    /** @return CleanRequestUrlParser */
    static public function instance() {
        if (empty(self::$instance)) {
            self::$instance = new CleanRequestUrlParser();
        }
        return self::$instance;
    }

    private function __construct() {
    }

    /** @return array */
    public function getExplodedCleanRequestUrl() {
        if (empty($this->explodedCleanRequestUrl)) {
            $explodedUrl = explode("/", $_SERVER["REQUEST_URI"]);
            $this->explodedCleanRequestUrl = array();
            foreach ($explodedUrl as $urlVar) {
                if (!empty($urlVar)) {
                    $this->explodedCleanRequestUrl[] = $urlVar;
                }
            }
        }
        return $this->explodedCleanRequestUrl;
    }

    /** @param int $offset */
    public function parseGetVars($offset) {
        // TODO: complete this function to set the $_GET superglobal
    }
}