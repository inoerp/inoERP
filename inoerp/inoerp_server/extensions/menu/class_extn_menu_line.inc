<?php

class extn_menu_line extends dbObject {

 public static $table_name = "extn_menu_line";
 public static $primary_column = "extn_menu_line_id";
 public static $parent_primary_column = "extn_menu_header_id";
 public static $key_column = 'extn_menu_header_id';
 public static $module = "extn";
 public $field_a = [
  'extn_menu_line_id',
  'extn_menu_header_id',
  'link_name',
  'description',
  'link_title',
  'path_id',
  'external_link',
  'interanl_link',
  'parent_id',
  'css_class',
  'icon_css_class',
  'priority',
  'dropdown_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $requiredField = [
  'extn_menu_header_id'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "extn_menu_header_id"
 ];
 public $extn_menu_line_id;
 public $extn_menu_header_id;
 public $link_name;
 public $description;
 public $link_title;
 public $path_id;
 public $external_link;
 public $interanl_link;
 public $parent_id;
 public $css_class;
 public $icon_css_class;
 public $priority;
 public $dropdown_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public static function find_by_headerId_and_buOrgId($extn_menu_header_id, $bu_org_id) {
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where extn_menu_header_id= '{$extn_menu_header_id}' AND bu_org_id= '{$bu_org_id}'  ";
   $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public function findBy_parentId($id, $order_by_field = '', $order_by_seq = 'ASC') {
  if ($this->effecitve_items_only) {
   /*
    * Check if revision exists. If yes, use revision else find all items where 
    * (bl.effective_end_date IS NULL OR bl.effective_end_date > CURRENT_DATE
    */
   $boh_i = bom_header::find_by_id($id);
   $item_rev = inv_item_revision::find_currentRev_by_itemIdM_orgId($boh_i->item_id_m, $boh_i->org_id, $this->revsion_effecitve_date);
   if ($item_rev) {
    $all_bom_lines = self::find_by_bomHeaderId_revNumber($id, $item_rev->revision_name);
   } else {
    $sql = " SELECT bl.bom_line_id, 	bl.bom_header_id, 	bl.bom_sequence, 	bl.routing_sequence, 	
     bl.component_item_id_m, 	bl.usage_basis, 	bl.usage_quantity, 	bl.auto_request_material_cb, 	
     bl.effective_start_date, 	bl.effective_end_date, 	bl.eco_number, 	bl.eco_implemented_cb, 	
     bl.planning_percentage, 	bl.yield, 	bl.include_in_cost_rollup_cb, 	bl.wip_supply_type, 	
     bl.supply_sub_inventory, 	bl.supply_locator, 	bl.ef_id, 	bl.created_by, 	bl.creation_date, 	
     bl.last_update_by, 	bl.last_update_date

     FROM      bom_line bl, 
     bom_header bh
     
     WHERE bh.bom_header_id = bl.bom_header_id 
     AND (bl.effective_end_date IS NULL OR bl.effective_end_date > CURRENT_DATE ) 
     AND bh.bom_header_id = '{$id}' 
     ORDER BY bl.bom_sequence ASC   ";
    $all_bom_lines = self::find_by_sql($sql);
   }
   return !empty($all_bom_lines) ? $all_bom_lines : false;
  } else {
   return parent::findBy_parentId($id, $order_by_field, $order_by_seq);
  }
 }

 private function _parent_explosion($parent_id, &$menu_ids) {
  $all_child_first_l = self::find_by_fieldVal(['parent_id' => $parent_id]);

  if (!empty($all_child_first_l)) {
   foreach ($all_child_first_l as $menu_line_i) {
    $menu_ids[$menu_line_i->extn_menu_line_id] = $menu_line_i;
    $this->_parent_explosion($menu_line_i->extn_menu_line_id, $menu_ids);
   }
  }

  return $menu_ids;
 }

 public function menu_explosion($extn_menu_header_id) {
  $all_child_first_l = self::find_by_fieldVal(['extn_menu_header_id' => $extn_menu_header_id, 'parent_id' => 'NULL'], 'extn_menu_line_id' , 'ASC');
  if(empty($all_child_first_l)){
   return;
  }
  $menu_ids_f = [];

  $key_count = 0;
  foreach ($all_child_first_l as $menu_line_i) {
   $menu_ids = [];
   $parent_r = $this->_parent_explosion($menu_line_i->extn_menu_line_id, $menu_ids);
   if (!empty($parent_r)) {

    $menu_ids_f[$key_count] = [];
    $menu_ids_f[$key_count]['childs'] = [];
    array_push($menu_ids_f[$key_count], $menu_line_i);
    foreach ($parent_r as $menu_chld) {
     array_push($menu_ids_f[$key_count]['childs'], $menu_chld);
    }
   } else {
    array_push($menu_ids_f, $menu_line_i);
   }
   $key_count++;
  }
  return $menu_ids_f;
 }

 public function show_menu_list($extn_menu_header_id) {
  $menu_h = extn_menu_header::find_by_id($extn_menu_header_id);
  if(empty($menu_h)){
   return false;
  }
  $menu_a = $this->menu_explosion($extn_menu_header_id);
  $menu_stmt = '<ul class="' . $menu_h->css_class . '">';
  foreach ($menu_a as $menu) {
   if (is_array($menu)) {
    $menu_stmt .= '<li role="presentation" class="dropdown">
        <a class="dropdown-toggle" data-toggle="dropdown" href="#" role="button" aria-expanded="false"><i class="' . $menu[0]->icon_css_class . '"></i>&nbsp; ' . $menu[0]->link_name . ' <span class="'.$menu[0]->css_class.'"></span></a>';
    $menu_stmt .= '<ul class="dropdown-menu" role="menu">';
    $menu_2_chl_a = $menu['childs'];
    foreach ($menu_2_chl_a as $k => $menu_2) {
     if (!empty($menu_2->path_id)) { 
      $path_j = path::find_by_id($menu_2->path_id);
      $link = HOME_URL . $path_j->path_link;
     } else if (!empty($menu_2->external_link)) {
      $link = $menu_2->external_link;
     } else {
      $link = HOME_URL . $menu_2->interanl_link;
     }
     $menu_stmt .= ' <li><a href="' . $link . '" title="' . $menu_2->link_title . '"   class="' . $menu_2->css_class . '" ><i class="' . $menu_2->icon_css_class . '"></i> &nbsp;' . $menu_2->link_name . '</a> </li>';
    }
    $menu_stmt .= '</ul> </li>';
   } else {
    if (!empty($menu->path_id)) {
     
    } else if (!empty($menu->external_link)) {
     $link = $menu->external_link;
    } else {
     $link = $menu->interanl_link;
    }

    $menu_stmt .= '<li><a href="' . $link . '" title="' . $menu->link_title . '"   class="' . $menu->css_class . '" ><i class="' . $menu->icon_css_class . '"></i> &nbsp;' . $menu->link_name . '</a></li>';
   }
  }

  $menu_stmt .= '</ul>';
  return $menu_stmt;
 }

}

$menu_line = new extn_menu_line();

//end of extn_menu_line class
?>