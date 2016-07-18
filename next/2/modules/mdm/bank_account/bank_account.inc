<?php

if (!empty($$class->ar_customer_id)) {
 $ac = new ar_customer();
 $ac->findBy_id($$class->ar_customer_id);
 $$class->customer_name = $ac->customer_name;
 $$class->customer_number = $ac->customer_number;
}

$customer_site_obj = [];
$supplier_site_obj = [];
if (!empty($$class->ar_customer_site_id)) {
 $arc = new ar_customer_site();
 $arc_i = $arc->findBy_id($$class->ar_customer_site_id);
 array_push($customer_site_obj, $arc_i);
}
if (!empty($$class->supplier_site_id)) {
 $supplier_site = supplier_site::find_by_id($$class->supplier_site_id);
 array_push($supplier_site_obj, $supplier_site);
}

if (!empty($$class->mdm_bank_header_id)) {
 $bh = new mdm_bank_header();
 $bh->findBy_id($$class->mdm_bank_header_id);
 $$class->bank_name = $bh->bank_name;
 $$class->bank_number = $bh->bank_number;
 $$class->bank_name_short = $bh->bank_name_short;
 $$class->bank_name_alt = $bh->bank_name_alt;
}

if (!empty($$class->mdm_bank_site_id)) {
 $bs = new mdm_bank_site();
 $bs->findBy_id($$class->mdm_bank_site_id);
 $$class->branch_name = $bs->branch_name;
 $$class->branch_number = $bs->branch_number;
 $$class->ifsc_code = $bs->ifsc_code;
 $$class->swift_code = $bs->swift_code;
 $$class->routing_number = $bs->routing_number;
 $$class->iban_code = $bs->iban_code;
}
?>