<?php

if(!empty($$class->am_asset_id)){
 $am_ast = am_asset::find_by_id($$class->am_asset_id);
 $$class->am_asset_number = $am_ast->asset_number;
}

if(!empty($$class->item_id_m)){
 $item_ams = item::find_by_id($$class->item_id_m);
 $$class->item_number = $item_ams->item_number;
}
//}
?>
