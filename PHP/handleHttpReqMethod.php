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
        echo json_encode($_GET);
        // do something ...
        break;

    case "POST":
        printRequestMethod();
        echo json_encode($_POST);
        // do something ...
        break;

    case "PUT":
        printRequestMethod();
        parse_str(file_get_contents("php://input"), $put_vars);
        echo json_encode($put_vars);
        // do something ...
        break;

    case "DELETE":
        printRequestMethod();
        parse_str(file_get_contents("php://input"), $delete_vars);
        echo json_encode($delete_vars);
        // do something ...
        break;

    default:
        break;
}
