<?php 
//$module='onhand';
$table_name='onhand_v';
$key_field = 'onhand';
$pageTitle = " Onhand - View quantity onhand details "; 
?>
<?php require_once("../../../include/basics/header.inc"); ?>
<?php require_once("onhand_functions.inc"); ?>
<script src="onhand.js"></script>
<div id='pageTitle'>Onhand Quantities</div>
<div id="structure">
    <div id="onhand">
        <div id="onhand_details">
            <h2>Onhand Quantities </h2>

            <div id="loading"><img alt="Loading..." 
                                   src="<?php echo HOME_URL; ?>themes/images/loading.gif"/></div>

            <br><br>
            <div id="onhand_search">
                <br>
                <form action="onhands.php" name="search_onhand" method="GET" class="search_box onhand_form" id="search_onhand">
                    <ul class="search_form">
                        <li><label>Item Number : </label>
                            <input type="text" id="item_number" name="item_number" value="<?php
                            echo!(is_array($_GET['item_number'])) ? htmlentities($_GET['item_number']) : "";
                            ?>" maxlength="50" >
                        </li>
                        <li><label>Item Description : </label>
                            <input type="text" id="item_description" name="item_description" value="<?php
                            echo!(is_array($_GET['item_description'])) ? htmlentities($_GET['item_description']) : "";
                            ?>" maxlength="50" >
                        </li>
                        <li><label>Inventory Org : </label>
                            <input type="text" id="org_name" name="org_name" value="<?php
                            echo!(is_array($_GET['org_name'])) ? htmlentities($_GET['org_name']) : "";
                            ?>" maxlength="50" >
                        </li>
                        <li><label>Sub Inventory : </label>
                            <input type="text" id="subinventory" name="subinventory" value="<?php
                            echo!(is_array($_GET['subinventory'])) ? htmlentities($_GET['subinventory']) : "";
                            ?>" maxlength="50" >
                        </li>
                        <li><label>Locator : </label>
                            <input type="text" id="locator" name="locator" value="<?php
                            echo!(is_array($_GET['locator'])) ? htmlentities($_GET['locator']) : "";
                            ?>" maxlength="50" >
                        </li>
                        <li><label>Onhand Id : </label>
                            <input type="text" id="onhand_id" name="onhand_id" value="<?php
                            echo!(is_array($_GET['onhand_id'])) ? htmlentities($_GET['onhand_id']) : "";
                            ?>" maxlength="50" >
                        </li>
                        <li>
                        <lable>Add dynamic search criteria </lable>
                        <select name="new_search_criteria" id="new_search_criteria" class="new_search_criteria"> 
                            <option value=""> </option>
                            <?php
                            foreach ($search_array as $key => $value) {
                                echo '<option value="' . htmlentities($value) . '"';
                                echo '>' . $value . '</option>';
                            }
                            ?> 
                        </select>
                        </li>
                        <li>
                            <input type="button" class="add button" id="new_search_criteria_add" value="Add">
                        </li>
                        <!--          send the existing column array to POST-->
                        <li><input type="hidden" name="column_array" id="column_array" value="<?php print base64_encode(serialize($column_array)) ?>" >
                        </li>
                    </ul>
                    <ul class="add_new_search">
                        <li>
                        <lable>Add a new column</lable>
                        <select name="new_column" id="new_column" > 
                            <option value=""> </option>
                            <?php
                            foreach ($search_array as $key => $value) {
                                echo '<option value="' . htmlentities($value) . '"';
                                echo '>' . $value . '</option>';
                            }
                            ?> 
                        </select>
                        </li>
                        <li>
                        <lable>Records per page</lable>
                        <select name="per_page" id="per_page" > 
                            <option value="10">10</option>
                            <option value="20" <?php echo $per_page == 20 ? " selected" : "" ?>>20</option>
                            <option value="50" <?php echo $per_page == 50 ? " selected" : "" ?>>50</option>
                            <option value="100" <?php echo $per_page == 100 ? " selected" : "" ?>>100</option>
                            <option value="1000" <?php echo $per_page == 1000 ? " selected" : "" ?>>1000</option>
                            <option value="all" <?php echo $per_page == "all" ? " selected" : "" ?>>All</option>
                            <option value="1" <?php echo $per_page == "1" ? " selected" : "" ?>>1</option>
                        </select>
                        </li>
                      <li>
                        <lable>Group by</lable>
                        <select name="group_by" id="group_by" > 
                            <option value="0">Locator</option>
                            <option value="1" <?php echo $group_by == "subinventory" ? " selected" : "" ?>>Sub Inventory</option>
                            <option value="2" <?php echo $group_by == "org_name" ? " selected" : "" ?>>Inventory</option>
                        </select>
                        </li>
                    </ul>
                    <ul class="form_buttons">
                        <li><a href="onhands.php" class="reset button"> Reset All</a></li>
                        <li><input type="submit" form="search_onhand" name="submit_search" class="search button" value="Search"></li>

                    </ul>
                </form> 

            </div>

            <?php
            if (!empty($total_count)) {
                echo '<h3>Total records : ' . $total_count . '</h3>';
            }
            ?>
            <div id="scrollElement">
                <div id="print">
                    <table class="normal">
                        <thead> 
                            <tr>
                                <?php
                                foreach ($column_array as $key => $value) {
                                    echo '<th>' . $value . '</th>';
                                }
                                ?>
                                
                            </tr>
                        </thead>

                        <?php
                        If (isset($result)) {
                            echo '<tbody>';
                            foreach ($result as $record) {
                                echo '<tr>';
                                foreach ($column_array as $key => $value) {
                                    switch ($group_by) {
                                        case "subinventory":
                                        $record->locator ="";
                                         $record->onhand ="";
                                        break;
                                       
                                        case "org_name":
                                         $record->onhand ="";
                                        $record->locator ="";
                                        $record->subinventory ="";
                                        break;

                                        default :
                                         
                                        break;
                                    }
                                
                                 echo '<td>' . $record->$value . '</td>';
                                }
                                
                                echo '</tr>';
                            }
                            echo '</tbody>';
                        }
                        ?>

                    </table>
                </div>
            </div>
            <div id="pagination" style="clear: both;">
                <?php
                if (isset($pagination) && $pagination->total_pages() > 1) {
                    if ($pagination->has_previous_page()) {
                        echo "<a href=\"onhands.php?page=";
                        echo $pagination->previous_page() . '&' . $query_string;
                        echo "\"> &laquo; Previous </a> ";
                    }

                    for ($i = 1; $i <= $pagination->total_pages(); $i++) {
                        if ($i == $page) {
                            echo " <span class=\"selected\">{$i}</span> ";
                        } else {
                            echo " <a href=\"onhands.php?page={$i}&" . remove_querystring_var($query_string, 'page');
                            echo '\">' . $i . '</a>';
                        }
                    }

                    if ($pagination->has_next_page()) {
                        echo " <a href=\"onhands.php?page=";
                        echo $pagination->next_page() . '&' . remove_querystring_var($query_string, 'page');
                        echo "\">Next &raquo;</a> ";
                    }
                }
                ?>
            </div>
            <!--download page creation-->
            <ul class="data_export">
                <li> <input type="submit" class="download button excel" value="<?php echo $per_page ?> Records" form="download"></li>
                <li> <input type="submit" class="download button excel" value="All Records" form="download_all"></li>
                <li> <input type="button" class="download button print" value="Print"></li>
            </ul>

            <?php
            if (!empty($sql)) {
                $onhand_obj = onhand::find_by_sql($sql);
                $onhand_array = json_decode(json_encode($onhand_obj), true);
            }
            ?>
            <!--download page form-->
            <form action="<?php echo HOME_URL; ?>download.php" method="POST" name="download" id="download">
                <input type="hidden"  name="data" value="<?php print base64_encode(serialize($onhand_array)) ?>" >

            </form>

            <!--download page creation for all records-->
            <?php
            if (!empty($all_download_sql)) {
                $onhand_obj_all = onhand::find_by_sql($all_download_sql);
                $onhand_array_all = json_decode(json_encode($onhand_obj_all), true);
            }
            ?>
            <!--download page form-->
            <form action="<?php echo HOME_URL; ?>download.php" method="POST" name="download_all" id="download_all">
                <input type="hidden"  name="data" value="<?php print base64_encode(serialize($onhand_array_all)) ?>" >
            </form>
            <!--download page completion-->

        </div>
    </div>
</div>
<!--   end of structure-->
<?php include_template('footer.inc') ?>
