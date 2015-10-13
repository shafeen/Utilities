<?
session_start();

if (isset($_POST["logout"])) {
    if(isset($_SESSION['authorized'])) {
        unset($_SESSION['authorized']);
    }
    session_unset();
    session_destroy();
} else if ($_POST["username"] == "shafeen") { // authorize if username == shafeen
    echo "User Authorized. Redirecting....";
    $_SESSION['authorized'] = 'true';
} else {
    echo "Unauthorized User: ";
    echo $_POST["username"];
}

header("Location: session-login.php");
exit();