<?php
$extension = 'page';
$key_field = 'content';
$pageTitle = " Page - Create & update contents ";
$required_field_flag = 1;
//$page_no=1;
//$per_page=10;
?>
<?php
include_once("../../include/basics/header.inc");
?>

<script src="page.js"></script>
<div id="structure">
 <div id="page">
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
    <?php if(!empty($page->page_id)) { ?>
<!--    show content if page_id exists-->
    <li>
     <div id="scrollElement">
      <div class="hidden"><input type="hidden" name="page_id" 
      value="<?php echo htmlentities($page->page_id); ?>"></div>
      <!--create empty form or a single id when search is not clicked and the id is referred from other page -->
      <div id="page_element"><ul><li><h3>
<?php echo htmlentities($page->subject); ?>" </h3>
      </li>
        <li class="created_by"><label>Author : </label>
<?php echo htmlentities($page->created_by); ?>
        </li>
        <li class="creation_date"><label>Date : </label>
        <?php echo htmlentities($page->creation_date); ?>
        </li>
        <li>
       <div class="edit">
        <a href="page.php?page_id=<?php echo htmlentities($page->page_id); ?>">
         Edit </a>
       </div>
        </li>
        </ul>
      </div>
      <div id="contentId">
<?php echo $page->content; ?>
      </div>
      <div id="terms"><label>Tags : </label>
<?php echo htmlentities($page->terms); ?>
      </div>
             <div id="attachment_page"><label>Attachments : </label>
      <?php 
      if(count($file)>0){
        foreach($file as $records){
       echo '<ul>';
       echo '<li><a href=' . HOME_URL .$records->file_path. $records->file_name . '>' . $records->file_name . '</a></li>';
     echo '</ul>';    
           }
      }
      
      ?>
     </div>
      <div id="page_navigation">
       <ul>

<?php if (!empty($page->parent_id)) { ?>
         <li class="parent_id"><label>Parent : </label>
          <a href="pages.php?page_id=<?php echo htmlentities($page->parent_id); ?>">
         <?php echo htmlentities($page->parent_id); ?> </a>
         </li>
<?php } ?>
       </ul>
      </div>
      <!--                 complete Showing a blank form for new entry-->

     </div>  


    </li>
   <!--Show all contents if page id doesnt exists-->   
 <?php } 
    else { ?>
        <div id="noOfpages">
   <form action="" method="get">
    <select name="per_page">
     <option value="3" <?php echo $per_page == 3 ? "selected" : "" ?>> 3 </option>
     <option value="5" <?php echo $per_page == 5 ? "selected" : "" ?>> 5 </option>
     <option value="10" <?php echo $per_page == 10 ? "selected" : "" ?>> 10 </option>
     <option value="20" <?php echo $per_page == 20 ? "selected" : "" ?>> 20 </option>
     <option value="50" <?php echo $per_page == 50 ? "selected" : "" ?>> 50 </option>
    </select>
    <input type="submit" class="button" value="Per Page">
   </form>
  </div> 
       <?php $sql = " SELECT * FROM  page ";
  if (!empty($per_page)) {
   $total_count = page::count_all();
   $pagination = new pagination($pageno, $per_page, $total_count);
   $sql .=" LIMIT {$per_page} ";
   $sql .=" OFFSET {$pagination->offset()}";
  }
  $result = page::find_by_sql($sql);

  foreach ($result as $records) {
   $page_summary = page::find_summary_by_id($records->page_id);
   echo '<div class="page_summary">';
   echo '<div class="subject_summary">';
   echo $page_summary->subject;
   echo '</div>';
   echo '<div class="content_summary">';
   echo $page_summary->content_summary;
   echo '</div>';
   echo '<div class="more_page">';
   echo '<a href="pages.php?page_id=' . $page_summary->page_id . '">';
   echo 'Read more.. </a>';
   echo '</div>';
   echo '</div>';
  }
  ?>  
         
   <div id="pagination" style="clear: both;">
                <?php
                if (isset($pagination) && $pagination->total_pages() > 1) {
                    if ($pagination->has_previous_page()) {
                        echo "<a href=\"pages.php?pageno=";
                        echo $pagination->previous_page() . '&' . $query_string;
                        echo "> &laquo; Previous </a> ";
                    }

                    for ($i = 1; $i <= $pagination->total_pages(); $i++) {
                        if ($i == $pageno) {
                            echo " <span class=\"selected\">{$i}</span> ";
                        } else {
                            echo " <a href=\"pages.php?pageno={$i}&" . remove_querystring_var($query_string, 'pageno');
                            echo '">' . $i . '</a>';
                        }
                    }

                    if ($pagination->has_next_page()) {
                        echo " <a href=\"pages.php?pageno=";
                        echo $pagination->next_page() . '&' . remove_querystring_var($query_string, 'pageno');
                        echo "\">Next &raquo;</a> ";
                    }
                }
                ?>
            </div>
    <?php 
    
                    } 
    ?>
   </ul>


  </div>
  <!--END OF FORM HEADER-->  
 </div>
</div>
<!--   end of structure-->

<?php include_template('footer.inc') ?>
