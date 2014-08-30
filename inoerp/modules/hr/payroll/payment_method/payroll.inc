<?php

 if (!empty($$class->bank_account_id)) {
  $ba = new mdm_bank_account();
  $ba->findBy_id($$class->bank_account_id);
  $$class->bank_header_id = $ba->mdm_bank_header_id;
  $$class->bank_site_id = $ba->mdm_bank_site_id;
  $$class->account_number = $ba->account_number;
  $$class->account_type = $ba->account_type;
  $$class->account_usage = $ba->account_usage;
  $$class->account_description = $ba->description;
   }

 if (!empty($$class->bank_header_id)) {
  $bh = new mdm_bank_header();
  $bh->findBy_id($$class->bank_header_id);
  $$class->bank_name = $bh->bank_name;
  $$class->bank_number = $bh->bank_number;
  $$class->bank_name_short = $bh->bank_name_short;
  $$class->bank_name_alt = $bh->bank_name_alt;
 }

 if (!empty($$class->bank_site_id)) {
  $bs = new mdm_bank_site();
  $bs->findBy_id($$class->bank_site_id);
  $$class->branch_name = $bs->branch_name;
  $$class->branch_number = $bs->branch_number;
  $$class->ifsc_code = $bs->ifsc_code;
  $$class->swift_code = $bs->swift_code;
  $$class->routing_number = $bs->routing_number;
  $$class->iban_code = $bs->iban_code;
 }
 
?>