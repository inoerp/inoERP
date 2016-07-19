<div id ="form_header">
 <form  method="post" id="<?php echo $class_first ?>"  name="<?php echo $class_first ?>">
  <span class="heading"><?php echo gettext(ucwords(str_replace('_', ' ', $class_first))) ?></span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Note') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field"> 
       <li>
        <?php
        if ($allow_search) {
         $f->l_text_field_dr_withSearch($class_id_first);
         echo '<a name="show" href="form.php?class_name="' . $class_first . '&mode=' . $mode . '" class="show document_id' . $class_id_first . '">
         <i class="fa fa-refresh"></i></a> ';
        } else {
         $f->l_text_field_dr($class_id_first, 'always_readonly');
        }
        ?> 
       </li>
       <?php
       if (!empty($tab1)) {
        foreach ($tab1 as $tab) {
         echo '<li>';
         ino_showField_from_details_a($tab);
         echo '</li>';
        }
       }
       ?>
      </ul>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <div> <?php echo ino_attachement($file) ?> </div>
     </div>
     <div id="tabsHeader-3" class="tabContent">
      <div> 
       <div id="comments">
        <div id="comment_list">
         <?php echo!(empty($comments)) ? $comments : ""; ?>
        </div>
        <div id ="display_comment_form">
         <?php
         $reference_table = 'extn_uprofile';
         $reference_id = $$class->extn_uprofile_id;
         ?>
        </div>
        <div id="new_comment">
        </div>
       </div>
      </div>
     </div>
    </div>

   </div>
  </div>


  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Other Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <?php
     $tab_count = 1;
     while ($tab_count <= $no_ofline_tabs) {
      if ($tab_count > 8) {
       exit;
      }
      $line_tab_var = 'line_tab_' . $tab_count;
      $line_tab_var_a = $$line_tab_var;
      echo '<li><a href="#tabsLine-1">' . gettext($line_tab_var_a['tab_heading']) . '</a></li>';
      $tab_count++;
     }
     ?>
    </ul>
    <div class="tabContainer"> 
     <?php
     $tab_count = 1;
     while ($tab_count <= $no_ofline_tabs) {
      if ($tab_count > 8) {
       exit;
      }
      $line_tab_var2 = 'line_tab_' . $tab_count;
      $line_tab_var2_a = $$line_tab_var2;
      $ul_class = isset($line_tab_var2_a['ul_class']) ? $line_tab_var2_a['ul_class'] : '';
      echo '<div id="tabsLine-1" class="tabContent"><div><ul>';
      echo "<ul class='{$ul_class}'>";
    
      if (!empty($line_tab_var2_a)) {
       foreach ($line_tab_var2_a as $tab_l) {
        if (!is_array($tab_l)) {
         continue;
        }
        echo '<li>';
        ino_showField_from_details_a($tab_l);
        echo '</li>';
       }
      }

      echo '</ul></div></div>';
      $tab_count++;
     }
     ?>
    </div>
   </div> 
  </div> 
 </form>
</div>


<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="<?php echo $class_first ?>" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="<?php echo $class_id_first ?>" ></li>
  <li class="form_header_id" data-form_header_id="<?php echo $class_first ?>" ></li>
  <?php
  if (!$allow_search) {
   echo '<li class="hideSearchPage" data-hideSearchPage="1" ></li>';
  }
  ?>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="<?php echo $class_id_first ?>" ></li>
  <li class="btn1DivId" data-btn1DivId="<?php echo $class_id_first ?>" ></li>
 </ul>
</div>