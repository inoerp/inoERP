<?php

$action_readonly = null;
if (empty($$class->fa_asset_book_info_id) && !empty($_GET['fa_asset_book_id']) && !empty($_GET['fa_asset_id'])) {
 $$class->fa_asset_book_id = $_GET['fa_asset_book_id'];
 $$class->fa_asset_id = $_GET['fa_asset_id'];
 $fa_abi_i = $$class->findBy_assetId_bookId();

 if ($fa_abi_i) {
  foreach ($fa_abi_i as $key => $val) {
//   $$class->$Key = $Val;
   if (property_exists($$class, $key)) {
    $$class->$key = $val;
   }
  }
 }
}
if (!empty($$class->fa_asset_book_id)) {
 $$class->asset_book_name = fa_asset_book::find_by_id($$class->fa_asset_book_id)->asset_book_name;
}

if (!empty($$class->fa_asset_id)) {
 $$class->asset_number = fa_asset::find_by_id($$class->fa_asset_id)->asset_number;
}

if (!empty($$class->fa_asset_book_id) && !empty($$class->fa_asset_id)) {
 $$class->accumulated_depreciation = fa_depreciation_header::find_depreciationSum_by_assetId_bookId($$class->fa_asset_id, $$class->fa_asset_book_id)->depreciation_amount;
 $$class->ytd_depreciation = fa_depreciation_header::find_ytdDepreciation_by_assetId_bookId($$class->fa_asset_id, $$class->fa_asset_book_id)->depreciation_amount;
}

if (!empty($$class->current_cost)) {
 $slvg_amount = !empty($$class->salvage_value_amount) ? $$class->salvage_value_amount : 0;
 $$class->recoverable_amount = $$class->current_cost - $slvg_amount;
}

if (empty($$class->status)) {
 $$class->status = 1;
}else if ($$class->status == 2) {
 $action_readonly = 1;
}
?>