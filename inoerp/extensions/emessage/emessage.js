$(document).ready(function () {
 $('body').off('click', '#new-emsg').on('click', '#new-emsg', function () {

  $('#user_name, .hidden.user_id, #text_message').val('');
  $('.row.emsg-all-messages').remove();
 });

 $('body').off('click', 'li.msg-lists').on('click', 'li.msg-lists', function () {
  $('body').find('.active-chat-list').removeClass('active-chat-list');
  $(this).addClass('active-chat-list');
  var extn_emessage_header_id = $(this).data('extn_emessage_header_id');
  var current_user_id = $('#current_user_id').val();
  getUserMessages({
   extn_emessage_header_id: extn_emessage_header_id,
   current_user_id: current_user_id
  });
  $('#user_name').val($(this).find('span.msg-list-username').text());
  $('#user_id').val($(this).find('span.msg-list-userid').data('user_id'));
  var newHeight = $('#chat-content-internal').height();
  $("#chat-content").animate({scrollTop: newHeight}, 'normal');
 });
// setInterval(refreshChatMessage, 2500);

 $('body').off('change', '#chat_mode').on('change', '#chat_mode', function () {
  if ($(this).val() == 'on') {
   si = setInterval(refreshChatMessage, 2500);
  } else {
   clearInterval(si);
  }
 });

 $('body').off('click', '#load-more-messages').on('click', '#load-more-messages', function () {
  loadMoreChatMessage($('p.extn_emessage_line_id').first().data('extn_emessage_line_id'));
  $(this).remove();
 });


});


function refreshChatMessage() {
 $('body').find('.active-chat-list').each(function () {
  var extn_emessage_header_id = $(this).data('extn_emessage_header_id');
  var current_user_id = $('#current_user_id').val();
  getUserMessages({
   extn_emessage_header_id: extn_emessage_header_id,
   current_user_id: current_user_id
  });
  $('#user_name').val($(this).find('span.msg-list-username').text());
  $('#user_id').val($(this).find('span.msg-list-userid').data('user_id'));
 });
}

function loadMoreChatMessage(extn_emessage_line_id) {
 $('body').find('.active-chat-list').each(function () {
  var extn_emessage_header_id = $(this).data('extn_emessage_header_id');
  var current_user_id = $('#current_user_id').val();
  getUserMessages({
   extn_emessage_header_id: extn_emessage_header_id,
   current_user_id: current_user_id,
   extn_emessage_line_id: extn_emessage_line_id
  });
  $('#user_name').val($(this).find('span.msg-list-username').text());
  $('#user_id').val($(this).find('span.msg-list-userid').data('user_id'));
 });
}

