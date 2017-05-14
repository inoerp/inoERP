<div id ="form_header">
 <div id="tabsHeader">
  <form action="" method="post" id="user_header" name="user_header"><span class="heading"><?php echo gettext('User Activities') ?> </span>
   <div id ="form_header">
    <div id="tabsHeader">
     <ul class="tabMain">
      <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
      <li><a href="#tabsHeader-2"><?php echo gettext('Posts') ?></a></li>
      <li><a href="#tabsHeader-3"><?php echo gettext('Comments') ?></a></li>
      <li><a href="#tabsHeader-4"><?php echo gettext('Recent Visit') ?></a></li>
      <li><a href="#tabsHeader-5"><?php echo gettext('Files') ?></a></li>
     </ul>
     <div class="tabContainer"> 
      <div id="tabsHeader-1" class="tabContent">
       <div class="large_shadow_box"> 
        <ul class="column two_column inRowLi">
         <li><label><?php echo gettext('User Name') ?> :</label>	<?php echo $$class->username; ?></li>
         <li><label><?php echo gettext('First Name') ?> : </label>	<?php echo $$class->first_name; ?> </li>
         <li><label><?php echo gettext('Last Name') ?> : </label><?php echo $$class->last_name; ?>	 </li>
         <li><label><?php echo gettext('Email Id') ?> :</label> <?php echo "xxx"; ?> </li>
         <li><label><?php echo gettext('Phone') ?> :</label> <?php echo $$class->phone; ?> </li>
         <li><label><?php echo gettext('Joined On') ?> :</label> <?php echo $$class->creation_date; ?> </li>
        </ul>
       </div>
      </div>
      <div id="tabsHeader-2" class="tabContent">
       <?php echo!empty($content_string) ? $content_string : false; ?>
      </div>
      <div id="tabsHeader-3" class="tabContent">
       <?php echo!empty($comment_string) ? $comment_string : false; ?>
      </div>
      <div id="tabsHeader-4" class="tabContent">
       <?php
       if (!empty($_SESSION['recent_visit'])) {
        $recent_visit = '<ul id="recent_visit">';
        $rev_a = array_reverse($_SESSION['recent_visit']);
        foreach ($rev_a as $k => $v) {
         if (!is_numeric($k)) {
          $recent_visit .= '<li><a href="' . $v . '">' . $k . '</a>';
         } else {
          $recent_visit .= '<li><a href="' . $v . '"> Vsiti ' . $k . '</a>';
         }
        }
        $recent_visit .= '</ul>';
       }
       echo $recent_visit;
       ?>
      </div>
      <div id="tabsHeader-5" class="tabContent">
       <div> <?php echo ino_attachement($file) ?> </div>
      </div>
     </div>

    </div>
   </div>
  </form>
 </div>
</div>  
