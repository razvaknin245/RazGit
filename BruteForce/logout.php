<?php
session_start();
require_once __DIR__ . '/destroy-session.php';
header('Location: index.php');
?>
