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
 * Asset Activities
 * Inventory, Non Inventory, Asset and Expense Items
 * Contains all the fp_mds_header information, such as - item_number, description ,  org_id, etc.
 * 
 */
// public $rev_enabled_cb;  needs to be dropped - use item rev only
class am_asset_activity extends item{
 
 public $pageTitle = " Asset Activity "; //page Title
 
}

//end of item class
?>