<?php
/**
 * User: Shafeen M.
 */

function printRequestMethod() {
    printf("This request was using %s\n", $_SERVER['REQUEST_METHOD']);
}

switch ($_SERVER["REQUEST_METHOD"]) {
    case "GET":
        printRequestMethod();
        // do something ...
        break;

    case "POST":
        printRequestMethod();
        // do something ...
        break;

    case "PUT":
        printRequestMethod();
        // do something ...
        break;

    case "DELETE":
        printRequestMethod();
        // do something ...
        break;

    default:
        break;
}


