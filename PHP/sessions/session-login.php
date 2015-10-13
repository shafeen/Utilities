<html>
<head>
    <title>PHP Sessions Test</title>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/2.1.3/jquery.min.js"></script>
</head>
<body>

<?
    session_start();
    if (!isset($_SESSION['authorized'])) {
?>
    <form action="session-authorize.php" method="post">
        <label for="username">Username</label>
        <input name="username" type="text" autocomplete="off"/>
        <button id="Login">Login</button>
    </form>
<?
    }
    else {
?>
    <div id="radiodiv">Click some radio buttons<br/>
        <input type="radio" name="choices" value="red">red<br/>
        <input type="radio" name="choices" value="blue">blue<br/>
        <input type="radio" name="choices" value="green">green<br/>
        <br/>
        <button id="logout">Logout</button>
    </div>
<?
    }
?>
    <script>
        $('input[type="radio"]').click(function (e) {
            $(e.target).parent().attr("style", "background-color:" + e.target.value);
        });

        $('button#logout').click(function (e) {
            $.post("session-authorize.php", {"logout" : "true"}).done(function (data) {
                location.reload();
            });
        });

    </script>
</body>
</html>