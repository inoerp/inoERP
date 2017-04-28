$('document').ready(function(){
 $('#folder-left').on('click', 'a' , function(){
  getFilesList({
   'extn_folder_id' : $(this).data('folder_id')
  });
 });
 
});