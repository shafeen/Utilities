<?

function setLoginChecksum($username) {
    $redis = new Redis();
    $redis->connect("127.0.0.1");
    $_SESSION['login_checksum'] = sha1(time());
    $redis->set($username."_checksum", $_SESSION['login_checksum']);
    $redis->close();
}

function getLoginChecksum($username) {
    $redis = new Redis();
    $redis->connect("127.0.0.1");
    $loginChecksum = $redis->get($username."_checksum");
    $redis->close();
    return $loginChecksum;
}

$correctUsername = "shafeen";

session_start();

if (isset($_POST["verify_session"])) {
    header('Content-Type: application/json');
    // TODO: complete this to check the session checksum
    echo json_encode(array("session_valid" => "f"));

} else if (isset($_POST["logout"])) {
    session_unset();
    session_destroy();
    header("Location: session-login.php");

} else if ((isset($_POST["username"]) && $_POST["username"] == $correctUsername)
    || $_SESSION['username']) { // authorize if username == $correctUsername
    if (!isset($_SESSION['authorized'])) {
        $_SESSION['authorized'] = 'true';
        $_SESSION['username'] = $_POST["username"];
        // cache (and store in db if appropriate) and set the login checksum
        setLoginChecksum($correctUsername);
        echo "User Authorized. Redirecting....";
    } else { // if authorized -> verify that only 1 session is running (latest is the only valid one)
        // verify the login_checksum
        $username = $_POST["username"];
        if ($_SESSION['login_checksum'] != getLoginChecksum($username)) {
            unset($_SESSION['authorized']);
            session_unset();
            session_destroy();
        }
    }
    header("Location: session-login.php");

} else {
    echo "Unauthorized User: ".$_POST["username"]."<br/>";
    header("Location: session-login.php");
}

exit();