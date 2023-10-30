<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="utf-8" />
  <meta name="author" content="Cody Duong" />
  <title>EECS 348 Lab Seven Practice Four</title>
  <link rel="stylesheet" href="globals.css">
</head>

<body>
  <nav id="nav"></nav>

  <main>
    <div>
      <h1>EECS 348 Lab Seven Practice Four</h1>
      <form action="practice4.php" method="post">
        Size of the multiplication table: <input type="text" name="size"><br>
        <input type="submit">
      </form>
      <div id="response">
        <!-- <?php
          if ($_SERVER["REQUEST_METHOD"] == "POST") {
            $number = intval($_POST["size"]);

            echo "<p>Multiplication Table for $number:</p>";

            echo "<table>";
            echo "<tr><th>&times;</th>";
            for ($i = 1; $i <= $number; $i++) {
                echo "<th>$i</th>";
            }
            echo "</tr>";

            for ($i = 1; $i <= $number; $i++) {
                echo "<tr><th>$i</th>";
                for ($j = 1; $j <= $number; $j++) {
                    $result = $i * $j;
                    echo "<td>$result</td>";
                }
                echo "</tr>";
            }

            echo "</table>";
          }
          ?> -->

          <?php
          if ($_SERVER["REQUEST_METHOD"] == "POST") {
            echo 'foo'
          }
        ?>
      </div>
    </div>
  </main>

  <script type="module" src="index.js"></script>

</body>

</html>