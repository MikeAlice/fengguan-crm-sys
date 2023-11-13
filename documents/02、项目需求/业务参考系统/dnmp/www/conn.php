<?php
$servername = "mysql-crm";
$username = "root";
$password = "123456";
try {
    $conn = new PDO("mysql:host=$servername;", $username, $password);
    echo "connect mysql success.";
}
catch(PDOException $e)
{
    echo $e->getMessage();
}
?>