<?
header('Content-Type: application/json');

session_start();

if (isset($_POST["logout"])) {
    if(isset($_SESSION['authorized'])) {
        unset($_SESSION['authorized']);
    }
    session_unset();
    session_destroy();
} else if ($_POST["username"] == "shafeen" || $_SESSION['username']) { // authorize if username == shafeen
    if (!isset($_SESSION['authorized'])) {
        $_SESSION['authorized'] = 'true';
        $_SESSION['username'] = $_POST["username"];
        // store the login checksum
        $redis = new Redis();
        $redis->connect("127.0.0.1");
        $_SESSION['login_checksum'] = sha1(time());
        $redis->set("shafeen_checksum", $_SESSION['login_checksum']);
        $redis->close();
        echo "User Authorized. Redirecting....";

    } else { // if authorized -> verify that only 1 session is running (latest is the only valid one)
        $redis = new Redis();
        $redis->connect("127.0.0.1");
        // verify the login_checksum
        if ($_SESSION['login_checksum'] != $redis->get("shafeen_checksum")) {
            unset($_SESSION['authorized']);
            session_unset();
            session_destroy();
        }
        $redis->close();
    }
} else {
    echo "Unauthorized User: ";
    echo $_POST["username"];
}

header("Location: session-login.php");
exit();