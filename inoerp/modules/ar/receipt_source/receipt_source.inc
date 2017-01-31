<?php

if (!empty($$class->mdm_bank_account_id)) {
 $ba = new mdm_bank_account_v();
 $ba->findBy_id($$class->mdm_bank_account_id);
 $$class->bank_name = $ba->bank_name;
 $$class->account_number = $ba->account_number;
 $$class->bank_number = $ba->bank_number;
 $$class->bank_name_short = $ba->bank_name_short;
 $$class->bank_name_alt = $ba->bank_name_alt;
 $$class->branch_name = $ba->branch_name;
 $$class->branch_number = $ba->branch_number;
 $$class->ifsc_code = $ba->ifsc_code;
 $$class->swift_code = $ba->swift_code;
 $$class->routing_number = $ba->routing_number;
 $$class->iban_code = $ba->iban_code;
}
?>