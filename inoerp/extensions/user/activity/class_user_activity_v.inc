<?php
/**
 * inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */
/**
 * 
 *
 */
class user_activity_v extends dbObject {

 public static $table_name = "user";
 public static $primary_column = "user_id";
 public static $key_column = 'item_id_m';
 public static $module = "fp";
 public static $system_info = [
  'name' => 'User Activity',
  'number' => '10026',
  'description' => 'Check User Activities',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'extn',
  'weight' => 26
 ];
 public $field_a = [
  'content_id',
  'content_type_id',
  'subject',
  'created_by',
  'creation_date',
  'published_cb',
  'user_id',
  'username',
  'first_name',
  'last_name',
  'major_category_id',
  'major_category',
  'category',
  'content_type',
 ];
 public $initial_search = [
  'item_number',
 ];
 public $pageTitle = " Forecast activity "; //page Title
 public $search_functions = [
  'Organization' => 'search_org_name',
  'Forecast ' => 'search_forecast_name',
  'Forecast Group ' => 'search_forecast_group',
 ];
 public $content_id;
 public $content_type_id;
 public $subject;
 public $created_by;
 public $creation_date;
 public $published_cb;
 public $user_id;
 public $username;
 public $first_name;
 public $last_name;
 public $major_category_id;
 public $major_category;
 public $category;
 public $category_id;
 public $content_type;
 public $reference_table;
 public $phone;

 public function user_contents() {

  $sql = " 
   SELECT con.content_id, con.content_type_id, con.subject, con.created_by, con.creation_date, con.published_cb,
   user.user_id, user.username, user.first_name, user.phone,
user.last_name, cr.major_category_id, maj_cat.category as major_category,cat.category, ct.content_type
FROM user, 
content con LEFT JOIN category_reference cr ON cr.reference_id = con.content_id AND reference_table ='content'
LEFT JOIN category maj_cat ON maj_cat.category_id = cr.major_category_id
LEFT JOIN category cat ON cat.category_id = cr.category_id
LEFT JOIN content_type ct ON ct.content_type_id = con.content_type_id
WHERE  con.created_by = user.user_id
";

  if (!empty($this->user_id)) {
   $sql .= " AND user.user_id = '{$this->user_id}' ";
  }
  if (!empty($this->username)) {
   $sql .= " AND user.username = '{$this->username}' ";
  }
  if (!empty($this->category)) {
   $sql .= " AND cat.category = '{$this->category}' ";
  }
  if (!empty($this->category_id)) {
   $sql .= " AND cat.category_id = '{$this->category_id}' ";
  }

  $result = $this->findBySql($sql);
  return !empty($result) ? $result : false;
 }

 public function user_comments() {

  $sql = " 
   SELECT com.comment_id, com.reference_table, com.reference_id, com.comment ,com.published_cb, com.creation_date, 
   user.user_id, user.username, user.first_name,
user.last_name, con.content_type_id
FROM user, 
comment com,
content con 
WHERE  com.created_by = user.user_id
AND com.reference_table = 'content'
AND con.content_id =  com.reference_id
";

  if (!empty($this->user_id)) {
   $sql .= " AND user.user_id = '{$this->user_id}' ";
  }
  if (!empty($this->username)) {
   $sql .= " AND user.username = '{$this->username}' ";
  }
  if (!empty($this->reference_table)) {
   $sql .= " AND com.reference_table = '{$this->reference_table}' ";
  }

  $result = $this->findBySql($sql);
  return !empty($result) ? $result : false;
 }

}

?>
