<?php require_once("include/basics/connection.php"); ?>
<?php require_once("include/function/functions.php"); ?>
<?php include_once("include/basics/header.php"); ?>
<div id="left-block">
    <h2>Menu</h2>
        <ul>
        <li> <a href="content.php">Web Site Contents</a></li>
        <li> <a href="new_user.php">Register new user</a></li>
        <li> <a href="logout.php">Log out</a></li>
    </ul>

</div>
<div id="strucure">
    <h1> Supplier Informations</h1>
<?php 
    
echo "<table width='550px' border='1px'>" ;

$suppliers= find_all_suppliers();
    while($supplier=mysql_fetch_array($suppliers)){
        echo "<tr><td><a href=\"content.php?supplier=" . urlencode($supplier['supplier_id']) .
                "\"> {$supplier["supp_name"]} </a></td>
            <td>{$supplier["supplier_number"]}</td></tr>";
        
        $supplier_sites = find_all_supplier_sites($supplier["supplier_id"]);
         While ($site_row=mysql_fetch_array($supplier_sites)){
              echo "<tr><td><a href=\"content.php?supplier_site=" . urlencode($site_row['supplier_site_id']) .
        "\"> {$site_row["supplier_site_name"]}</td>
                  <td>{$site_row["supplier_site_number"]} </td></tr>";
                  
        }
        
    }
    echo "</table>" ;
    
    ?>
</div>
 </div>
<div id="right-block">Content for Right Block

</div>
                 
<?php require("include/basics/fotter.php"); ?>