<?php include_once('engine/install/install.php'); ?>

<?php 
if ($_GET["action"] == 'option')
{
echo "Works";
}


?>

<div id="structure">
    
    <p>hello <a href="extensions/user/user.php?uid=<?php echo $_SESSION['user_id']; ?>">
        <?php echo $_SESSION['user_name'] .'!'  ; ?></a>
      
  <p>
  <h1>Welcome to inoERP installation</h1>
  <h2> Install System Options </h2>
  <p><b><u>Options</u></b> <br/>
    Option header <br>
    Option Line <br>
   <input type="button" onclick="window.location='install.php?action=option'; ">
    
   
    </p>
</div>

 
<?php include_template('footer.inc') ?>
    


       
