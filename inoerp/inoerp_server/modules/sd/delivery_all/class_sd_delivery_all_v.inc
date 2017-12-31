<?php

class sd_delivery_all_v extends dbObject {

 public static $form_class_name = "sd_delivery_header";
 public static $table_name = "sd_delivery_all_v";
 public static $primary_column = "sd_delivery_header_id";
 public $field_a = [
  'sd_delivery_header_id',
  'delivery_number',
  'carrier',
  'vehicle_number',
  'handling_instruction',
  'delivery_shipped_quantity',
  'delivery_status',
  'sd_so_header_id',
  'bu_org_id',
  'document_type',
  'so_number',
  'ar_customer_id',
  'ship_to_id',
  'bill_to_id',
  'ar_customer_site_id',
  'hr_employee_id',
  'sales_person',
  'doc_currency',
  'header_amount',
  'so_status',
  'payment_term_id',
  'customer_name',
  'customer_number',
  'customer_site_name',
  'customer_site_number',
  'sd_so_line_id',
  'line_type',
  'line_number',
  'item_id_m',
  'kit_cb',
  'kit_configured_cb',
  'bom_config_header_id',
  'wip_wo_header_id',
  'item_description',
  'line_description',
  'line_quantity',
  'picked_quantity',
  'shipped_quantity',
  'unit_price',
  'line_price',
  'line_status',
  'requested_date',
  'promise_date',
  'schedule_ship_date',
  'actual_ship_date',
  'item_number',
  'uom_id',
  'item_status',
  'org',
  'shipping_org_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
  'address',
  'country',
  'postal_code',
  'phone',
  'email',
  'website',
  'address_b',
  'country_b',
  'postal_code_b',
  'phone_b',
  'email_b',
  'website_b',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1
 ];
 public $pageTitle = " Delivery "; //page Title

 public $sd_delivery_header_id;
 public $delivery_number;
 public $carrier;
 public $vehicle_number;
 public $handling_instruction;
 public $delivery_shipped_quantity;
 public $delivery_status;
 public $sd_so_header_id;
 public $bu_org_id;
 public $document_type;
 public $so_number;
 public $ar_customer_id;
 public $ship_to_id;
 public $bill_to_id;
 public $ar_customer_site_id;
 public $hr_employee_id;
 public $sales_person;
 public $doc_currency;
 public $header_amount;
 public $so_status;
 public $payment_term_id;
 public $customer_name;
 public $customer_number;
 public $customer_site_name;
 public $customer_site_number;
 public $sd_so_line_id;
 public $line_type;
 public $line_number;
 public $item_id_m;
 public $kit_cb;
 public $kit_configured_cb;
 public $bom_config_header_id;
 public $wip_wo_header_id;
 public $item_description;
 public $line_description;
 public $line_quantity;
 public $picked_quantity;
 public $shipped_quantity;
 public $unit_price;
 public $line_price;
 public $line_status;
 public $requested_date;
 public $promise_date;
 public $schedule_ship_date;
 public $actual_ship_date;
 public $item_number;
 public $uom_id;
 public $item_status;
 public $org;
 public $shipping_org_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $address;
 public $country;
 public $postal_code;
 public $phone;
 public $email;
 public $website;
 public $address_b;
 public $country_b;
 public $postal_code_b;
 public $phone_b;
 public $email_b;
 public $website_b;

 private function create_sd_delivery_all_v() {
  $sql = "
CREATE OR REPLACE VIEW sd_delivery_all_v
(
sd_delivery_header_id, delivery_number,  carrier ,  vehicle_number,  handling_instruction,
delivery_shipped_quantity ,delivery_status,
sd_so_header_id, bu_org_id, document_type, so_number, ar_customer_id, ship_to_id,bill_to_id,
ar_customer_site_id, hr_employee_id, doc_currency,  header_amount, so_status, payment_term_id,
customer_name, customer_number,
customer_site_name, customer_site_number,
sd_so_line_id, line_type, line_number,	item_id_m, 
kit_cb, kit_configured_cb, bom_config_header_id,	wip_wo_header_id, 
item_description, line_description, line_quantity,
picked_quantity, shipped_quantity, unit_price, line_price, line_status,
requested_date, promise_date , schedule_ship_date ,actual_ship_date,
item_number, uom_id, item_status,
org, shipping_org_id,
created_by, creation_date, last_update_by, last_update_date,
address,country,postal_code,phone,email,website,
address_b,country_b,postal_code_b, phone_b, email_b, website_b,
sales_person
)
AS
  SELECT
  sddh.sd_delivery_header_id, sddh.delivery_number,  sddh.carrier ,  sddh.vehicle_number,  sddh.handling_instruction,
  sddl.shipped_quantity as 	shipped_quantity , sddl.delivery_status as delivery_status,
  sdsh.sd_so_header_id, sdsh.bu_org_id, sdsh.document_type, sdsh.so_number, sdsh.ar_customer_id, sdsh.ship_to_id,sdsh.bill_to_id,
  sdsh.ar_customer_site_id, sdsh.hr_employee_id, sdsh.doc_currency,  sdsh.header_amount, sdsh.so_status, sdsh.payment_term_id,
  ar_customer.customer_name, ar_customer.customer_number,
  ar_customer_site.customer_site_name, ar_customer_site.customer_site_number,
  sdsl.sd_so_line_id, sdsl.line_type, sdsl.line_number,	sdsl.item_id_m, 
  sdsl.kit_cb, sdsl.kit_configured_cb, sdsl.bom_config_header_id,	sdsl.wip_wo_header_id, 
  sdsl.item_description, sdsl.line_description, sdsl.line_quantity,
  sdsl.picked_quantity, sdsl.shipped_quantity, sdsl.unit_price, sdsl.line_price, sdsl.line_status,
  sdsl.requested_date, sdsl.promise_date , sdsl.schedule_ship_date ,sdsl.actual_ship_date,
  item.item_number, item.uom_id, item.item_status,
  org.org, sdsl.shipping_org_id,
  sdsl.created_by, sdsl.creation_date, sdsl.last_update_by, sdsl.last_update_date,
  ship_address.address,ship_address.country,ship_address.postal_code,ship_address.phone,ship_address.email,ship_address.website,
  bill_address.address as address_b,bill_address.country as country_b,bill_address.postal_code as postal_code_b,
  bill_address.phone as phone_b,bill_address.email as email_b,bill_address.website as website_b,
  CONCAT(hre.last_name, ', ' , hre.first_name) as sales_person
  FROM 
  sd_delivery_header sddh, 
  sd_delivery_line sddl,
  ar_customer, 
  item,
  org,
  address as ship_address,
  address as bill_address,
  sd_so_header sdsh
  LEFT JOIN hr_employee hre ON sdsh.hr_employee_id = hre.hr_employee_id
  LEFT JOIN ar_customer_site ON sdsh.ar_customer_site_id = ar_customer_site.ar_customer_site_id,
  sd_so_line sdsl
  

  WHERE
  sdsh.sd_so_header_id = sdsl.sd_so_header_id
  AND sdsh.ar_customer_id = ar_customer.ar_customer_id
  AND sdsl.item_id_m = item.item_id_m AND item.org_id = sdsl.shipping_org_id
  AND sdsl.shipping_org_id = org.org_id
  AND sddh.sd_delivery_header_id = sddl.sd_delivery_header_id
  AND sddl.sd_so_line_id = sdsl.sd_so_line_id 
  AND ship_address.address_id = sdsh.ship_to_id
  AND bill_address.address_id = sdsh.bill_to_id

";
 }

 public function findBY_soLineId($line_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE sd_so_line_id = :sd_so_line_id ";
  $sql = ino_perPageSql_i($sql, 1);
  $value_a = ['sd_so_line_id' => $line_id];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of so_detail class
?>