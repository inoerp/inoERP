<?php include_once(__DIR__."/../../includes/basics/basics.inc"); ?>

<?php
if (!empty($_GET['extn_emessage_header_id']) && !empty($_GET['current_user_id'])) {
 $return_stmt = '';
 $extn_emessage_header_id = $_GET['extn_emessage_header_id'];
 $current_user_id = $_GET['current_user_id'];
 $return_stmt .='<div id="new_msg_content">';
 $return_stmt .= $f->hidden_field('extn_emessage_header_id', $extn_emessage_header_id);
 $return_stmt .= $f->hidden_field('extn_emessage_header_id', $extn_emessage_header_id);
 $all_msgs = extn_emessage_line::find_by_parent_id_k($extn_emessage_header_id);
 if ($all_msgs) {
  foreach (array_reverse($all_msgs) as $k => $msg) {
   $msg_class = $msg->from_user_id == $current_user_id ? ' msg_from_current_user pull-right ' : ' msg_from_other_user pull-left ';
   $return_stmt .= '<div class="complete_msg_div ' . $msg_class . ' ">';
   $return_stmt .= '<div class="row emsg-all-messages">
              <div class="col-lg-12">
             <p class="text-muted small msg_creation_date" data->' . $msg->creation_date . '</p>
             <p class="user-message">' . $msg->text_message . '</p>
            </div>
           </div>';
   $return_stmt .= '</div> <div class="clearfix"></div>';

  }
 }

 $return_stmt .= '</div>';
 echo $return_stmt;
}else{
 return null;
}
?>