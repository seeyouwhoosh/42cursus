(function ($) {
  $(document).ready(function () {
    $('.blogarise-btn-get-started').on('click', function (e) {
      e.preventDefault();
      if (!blogarise_ajax_object.can_install) {
        alert(blogarise_ajax_object.i18n.error_access);
        return;
      }
      var $btn = $(this);
      $btn.html(blogarise_ajax_object.i18n.processing).addClass('updating-message');
      $.post(blogarise_ajax_object.ajax_url, {
        action: 'install_act_plugin',
        security: blogarise_ajax_object.install_nonce
      }, function (response) {
        if (response.success) {
          window.location.href = 'admin.php?page=ansar-demo-import';
        } else {
          alert(response.data?.message || blogarise_ajax_object.i18n.failed);
          $btn.html(blogarise_ajax_object.i18n.try_again).removeClass('updating-message');
        }
      }).fail(function () {
        alert(blogarise_ajax_object.i18n.error_generic);
        $btn.html(blogarise_ajax_object.i18n.try_again).removeClass('updating-message');
      });
    });
  });
  $(document).on('click', '.notice-get-started-class .notice-dismiss', function () {
    var type = $(this).closest('.notice-get-started-class').data('notice');
    $.post(ajaxurl, {
      action: 'blogarise_dismissed_notice_handler',
      type: type,
    });
  });
})(jQuery);