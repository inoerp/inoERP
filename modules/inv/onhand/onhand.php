<?php 
$module='onhand';
$key_field = 'onhand';
$pageTitle = " Onhand - View quantity onhand details "; 
?>
<?php include_once("../../../include/basics/header.inc"); ?>
<script src="onhand.js"></script>

<?php
$onhand_search = "";
if ((!empty($_POST)) OR (!empty($_GET))) {
    if (is_array($_GET['onhand'])) {
        $onhand_search = "";
    } else {
        if (!empty($_GET['onhand'])) {
            $onhand_search = $_GET['onhand'];
        } else {
            if (!empty($_POST['onhand']) && is_array($_POST['onhand'])) {
                $onhand_search = "";
            } else {
                if (!empty($_POST['onhand'])) {
                    $onhand_search = $_POST['onhand'];
                }
            }
        }
    }
}
?>
<div id="structure">
    <div id="onhand">
        <div id="form_top">
            <ul class="form_top">
                <li><input type="button" class="button refresh" value="Refresh" name="refresh"/> </li>
                <li> <a class="button" href="onhand.php">New Object</a> </li>
                <li><input type="button" id="add_object" class="button" value="New Line" name="add_object"/> </li>
                <li><input type="submit" form="onhand_header" name="submit_onhand" id="submit_onhand" class="button" Value="Save"></li>
                <li> <input type="button" class="button remove_row" id="remove_row" Value="Remove"></li>
                <li> <input type="submit" class="button delete" form="coa_combination_form" name="delete_row" id="delete_row" value="Delete"></li>
                <li><input type="reset" class="button" form="onhand_header" name="reset" Value="Reset All"></li>
                <li><script>document.write('<a class="button" href="' + document.referrer + '">Go Back</a>');</script></li>
            </ul>
        </div>
        <!--    START OF FORM HEADER-->
        <div id ="form_header">
            <ul id="form_box"> 
                <li>

                    <div id="loading"><img alt="Loading..." 
                                           src="<?php echo HOME_URL; ?>themes/images/loading.gif"/></div>
                </li>
                <li>   <!--    Place for showing error messages-->

                    <?php
                    if (!empty($msg)) {
                        echo '<div id="dialog_box">';
                        if (is_array($msg)) {
                            foreach ($msg as $key => $value) {
                                $x = $key + 1;
                                echo 'Message ' . $x . ' : ' . $value . '<br />';
                            }
                        } else {
                            echo $msg;
                        }

                        echo '</div>';
                    }
                    ?> 

                    <!--    End of place for showing error messages-->
                </li>
                <!--Search form creation    -->
                <li>
                    <div id="onhand_search">
                        <br>
                        <form action="onhand.php" name="search_onhand" method="GET" class="search_box onhand_form" id="search_onhand">
                            <ul class="search_form">
                                <li><label>Locator Id : </label>
                                    <input type="text" id="onhand_id" name="onhand_id" value="<?php
                                    echo!(is_array($_GET['onhand_id'])) ? htmlentities($_GET['onhand_id']) : "";
                                    ?>" maxlength="50" >
                                </li>
                                <li><label>Sub Inventory Id : </label>
                                    <input type="text" id="subinventory_id" name="subinventory_id" value="<?php
                                    echo!(is_array($_GET['subinventory_id'])) ? htmlentities($_GET['subinventory_id']) : "";
                                    ?>" maxlength="50" >
                                </li>
                                <li><label>Inventory Id : </label>
                                    <input type="text" id="org_id" name="org_id" value="<?php
                                    echo!(is_array($_GET['org_id'])) ? htmlentities($_GET['org_id']) : "";
                                    ?>" maxlength="50" >
                                </li>
                                <li><label>Locator: </label>
                                    <input type="search" name="onhand" id="onhand" value="<?php echo $onhand_search; ?>"  maxlength="50" >
                                </li>
                                <li>
                                    <label>Alias : </label>
                                    <input id="alias" type="search" maxlength="50" value="<?php
                                    echo!(is_array($_GET['alias'])) ? htmlentities($_GET['alias']) : "";
                                    ?>" name="alias">
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
                            </ul>
                            <ul class="form_buttons">
                                <li><a href="onhand.php" class="reset button"> Reset All</a></li>
                                <li><input type="submit" form="search_onhand" name="submit_search" class="search button" value="Search"></li>

                            </ul>
                        </form> 

                    </div>
                </li>
                <li>
                    <div id="scrollElement">
                        <form action="onhand.php"  method="post" id="onhand_header"  name="onhand_header">
                            <?php if (!empty($result)) {
                                ?>
                                <?php
                                if (!empty($total_count)) {
                                    echo '<h3>Total records : ' . $total_count . '</h3>';
                                }
                                ?>

                                <ul>
                                    <li class="ncontrol"><span class="heading">Locator </span> 
                                        <table class="form_table">
                                            <tr>

                                            </tr>
                                        </table>
                                        <table class="form_table">
                                            <?php echo onhand::$view_table_line_tr ?>
                                            <tbody class="onhand_values">
                                                <?php
                                                $count = 0;
                                                foreach ($result as $onhand) {
                                                    ?>         
                                                    <tr id="onhand_values<?php echo $count ?>">
                                                        <td>    
                                                            <ul class="inline_action">
                                                                <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                                                                <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                                                                <li><input type="checkbox" name="onhand_id_cb" value="<?php echo htmlentities($onhand->onhand_id); ?>"></li>           
                                                            </ul>
                                                        </td>
                                                        <td>
                                                            <select name="org_id[]" id="org_id" class="org_id" required> 
                                                                <option value=""> </option>
                                                                <?php
                                                                $inventory_org = org_header::find_all_inventory_org();
                                                                foreach ($inventory_org as $key => $value) {
                                                                    echo '<option value="' . htmlentities($value->org_id) . '"';
                                                                    echo ($onhand->org_id == $value->org_id) ? " selected" : "";
                                                                    echo '>' . $value->name . '</option>';
                                                                }
                                                                ?> 
                                                            </select>
                                                        </td>
                                                        <td>
                                                            <select name="subinventory_id[]"  id="subinventory_id" class="subinventory_id" required >
                                                                <?php
                                                                $subinventory_of_org = subinventory::find_all_of_org_id($onhand->org_id);
                                                                foreach ($subinventory_of_org as $key => $value) {
                                                                    echo '<option value="' . $value->subinventory_id . '"';
                                                                    echo ($onhand->subinventory_id == $value->subinventory_id) ? " selected" : "";
                                                                    echo '>' . $value->subinventory . '</option>';
                                                                }
                                                                ?>
                                                            </select>
                                                        </td>
                                                        <td>
                                                            <input type="text" maxlength="250" size="50" name="onhand_structure" id="onhand_structure" class="onhand_structure" required 
                                                                   value="<?php
                                                                   $onhand_structure_array = onhand::onhand_structure();
                                                                   foreach ($onhand_structure_array as $key => $value) {
                                                                       echo htmlentities($value->option_line_code) . '.';
                                                                   }
                                                                   ?>">
                                                        </td>
                                                        <td>
                                                            <input type="text" readonly name="onhand_id[]" 
                                                                   value="<?php echo htmlentities($onhand->onhand_id); ?>" size="10"                           
                                                                   maxlength="50" class="onhand_id" placeholder="Sys generated number"> 
                                                        </td>

                                                        <td>
                                                            <input type="text" name="onhand[]" required value="<?php echo htmlentities($onhand->onhand); ?>" 
                                                                   size="15" maxlength="150"  id="onhand"> 
                                                        </td>
                                                        <td>
                                                            <input type="text" name="alias[]" value="<?php echo htmlentities($onhand->alias); ?>" 
                                                                   size="15" maxlength="150"  id="alias"> 
                                                        </td>
                                                        <td>
                                                            <input type="text" name="ef_id[]" value="<?php echo htmlentities($onhand->ef_id); ?>" 
                                                                   size="15" maxlength="10"  id="ef_id"> 
                                                        </td>
                                                        <td>                      
                                                            <Select name="status[]" id="status" >
                                                                <option value="" ></option>
                                                                <option value="enabled" 
                                                                        <?php echo $onhand->status == 'enabled' ? ' selected' : ''; ?> >Enabled</option>
                                                                <option value="disabled" 
                                                                        <?php echo $onhand->status == 'disabled' ? ' selected' : ''; ?> >Disabled</option>                                   
                                                            </select>

                                                        </td>
                                                        <td>
                                                            <input type="checkbox" name="rev_enabled<?php echo $count; ?>" 
                                                                   value="1"
                                                                   <?php
                                                                   if ($onhand->rev_enabled == 1) {
                                                                       echo " checked";
                                                                   } else {
                                                                       echo "";
                                                                   }
                                                                   ?> >  
                                                        </td> 
                                                        <td>
                                                            <input type="text" name="rev_number[]" value="<?php echo htmlentities($onhand->rev_number); ?>" 
                                                                   maxlength="50" size="5"  id="rev_number" class="rev_number"> 
                                                        </td> 
                                                    </tr>
                                                    <?php
                                                    $count = $count + 1;
                                                }
                                                ?>
                                            </tbody>
                                        </table>
                                    </li>
                                </ul>

                            <?php
                            } else {
                                $count = 0;
                                ?>
                                <!--create empty form or a single id when search is not clicked and the id is referred from other page -->

                                <ul>
                                    <li class="ncontrol"><span class="heading">Locator </span> 
                                        <table class="form_table">
                                            <tr>
                                                <td><lable>Inventory Org </lable>
                                            <select name="org_id[]" id="org_id" class="org_id" required> 
                                                <option value=""> </option>
                                                <?php
                                                $inventory_org = org_header::find_all_inventory_org();
                                                foreach ($inventory_org as $key => $value) {
                                                    echo '<option value="' . htmlentities($value->org_id) . '"';
                                                    echo ($onhand->org_id == $value->org_id) ? " selected" : "";
                                                    echo '>' . $value->name . '</option>';
                                                }
                                                ?> 
                                            </select>
                                            </td>
                                            <td><lable>Sub Inventory </lable>
                                            <select name="subinventory_id[]" id="subinventory_id" class="subinventory_id" required> 
                                                <option value=""> </option>
                                            </select>
                                            </td>
                                            <td><lable>Locator Structure </lable>
                                            <input type="text" maxlength="250" size="50" name="onhand_structure" id="onhand_structure" class="onhand_structure" required 
                                                   value="<?php
                                                   $onhand_structure_array = onhand::onhand_structure();
                                                   foreach ($onhand_structure_array as $key => $value) {
                                                       echo htmlentities($value->option_line_code) . '-';
                                                   }
                                                   ?>">
                                            </td>
                                            </tr>
                                        </table>
                                        <table class="form_table">
    <?php echo onhand::$table_line_tr ?>
                                            <tbody class="onhand_values">
                                                <tr id="onhand_values<?php echo $count ?>">
                                                    <td>    
                                                        <ul class="inline_action">
                                                            <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                                                            <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                                                            <li><input type="checkbox" name="onhand_id_cb" value="<?php echo htmlentities($onhand->onhand_id); ?>"></li>           
                                                        </ul>
                                                    </td>
                                                    <td>
                                                        <input type="text" readonly name="onhand_id[]" 
                                                               value="<?php echo htmlentities($onhand->onhand_id); ?>" size="10"                           
                                                               maxlength="50" class="onhand_id" placeholder="Sys generated number"> 
                                                    </td>

                                                    <td>
                                                        <input type="text" name="onhand[]" required value="<?php echo htmlentities($onhand->onhand); ?>" 
                                                               size="40" maxlength="250"  id="onhand"> 
                                                    </td>
                                                    <td>
                                                        <input type="text" name="alias[]" value="<?php echo htmlentities($onhand->alias); ?>" 
                                                               size="25" maxlength="150"  id="alias"> 
                                                    </td>
                                                    <td>
                                                        <input type="text" name="ef_id[]" value="<?php echo htmlentities($onhand->ef_id); ?>" 
                                                               size="15" maxlength="10"  id="ef_id"> 
                                                    </td>
                                                    <td>                      
                                                        <Select name="status[]" id="status" >
                                                            <option value="" ></option>
                                                            <option value="enabled" 
                                                                    <?php echo $onhand->status == 'enabled' ? ' selected' : ''; ?> >Enabled</option>
                                                            <option value="disabled" 
    <?php echo $onhand->status == 'disabled' ? ' selected' : ''; ?> >Disabled</option>                                   
                                                        </select>

                                                    </td>
                                                    <td>
                                                        <input type="checkbox" name="rev_enabled<?php echo $count; ?>" 
                                                               value="1"
                                                               <?php
                                                               if ($onhand->rev_enabled == 1) {
                                                                   echo " checked";
                                                               } else {
                                                                   echo "";
                                                               }
                                                               ?> >  
                                                    </td> 
                                                    <td>
                                                        <input type="text" name="rev_number[]" value="<?php echo htmlentities($onhand->rev_number); ?>" 
                                                               maxlength="50" size="5"  id="rev_number" class="rev_number"> 
                                                    </td> 
                                                </tr>
                                            </tbody>
                                        </table>
                                    </li>
                                </ul>

                                <?php
                                $count = $count + 1;
                            }
                            ?>
                            <!--                 complete Showing a blank form for new entry-->
                        </form>
                    </div>  

                </li>
            </ul>
            <div id="pagination" style="clear: both;">
                <?php
                if (isset($pagination)) {
                    if ($pagination->has_previous_page()) {
                        echo "<a href=\"onhand.php?page=";
                        echo $pagination->previous_page() . '&' . $query_string;
                        echo "\"> &laquo; Previous </a> ";
                    }

                    for ($i = 1; $i <= $pagination->total_pages(); $i++) {
                        if ($i == $page) {
                            echo " <span class=\"selected\">{$i}</span> ";
                        } else {
                            echo " <a href=\"onhand.php?page={$i}&" . remove_querystring_var($query_string, 'page');
                            echo '&submit_search=Search';
                            echo '\">' . $i . '</a>';
                        }
                    }

                    if ($pagination->has_next_page()) {
                        echo " <a href=\"onhand.php?page=";
                        echo $pagination->next_page() . '&' . remove_querystring_var($query_string, 'page');
                        echo '&submit_search=Search';
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
        <!--END OF FORM HEADER-->  
    </div>
</div>
<!--   end of structure-->

<?php include_template('footer.inc') ?>
