<form  method="post" id="extn_folder"  name="extn_folder">
 <div id ="form_header">
	<span class="heading"><?php echo gettext('Files & Folders') ?></span>

	<div id="folder-left" class="tree well col-md-3 menu" >
	 <h2><?php echo gettext('Folder Navigator') ?></h2>
	 <?php $$class->full_folder_explosion_view(); ?>
	</div>

	<div id="folder-right" class="tree well col-md-9">
	 <table class='table table-striped table-bordered'>
		<thead><tr><th class="col-md-1 text-center">Org</th><th class="col-md-1 text-center">Reference</th><th class="col-md-2 text-center">Reference Id</th><th class="col-md-2">File Name</th><th class="col-md-2">Created On</th><th class="col-md-3">File Description</th></tr></thead>
		<tbody id="folder-content">

		</tbody>
	 </table>
	</div>
 </div> 
</form>	


