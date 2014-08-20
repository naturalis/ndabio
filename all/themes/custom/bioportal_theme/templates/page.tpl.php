<!--.page -->
<div role="document" class="page">

  <!--.l-header region -->
  <header role="navigation" class="l-header" id="top-bar-wrapper">

    <?php if ($top_bar): ?>
      <!--.top-bar -->
      <?php if ($top_bar_classes): ?>
      <div class="<?php print $top_bar_classes; ?>">
      <?php endif; ?>
        <nav class="top-bar" data-topbar <?php print $top_bar_options; ?>>
          <ul class="title-area">
            <li class="name"><h1><?php print $linked_site_name; ?></h1></li>
            <li class="toggle-topbar menu-icon"><a href="#"><span><?php print $top_bar_menu_text; ?></span></a></li>
          </ul>
          <section class="top-bar-section">
            <?php if ($top_bar_main_menu) :?>
              <?php print $top_bar_main_menu; ?>
            <?php endif; ?>

            <?php if ($top_bar_secondary_menu) :?>
              <?php print $top_bar_secondary_menu; ?>
            <?php endif; ?>

            <?php if ($language_menu): ?>
                <?php print $language_menu; ?>
            <?php endif; ?>

            <ul class="right" id="help">
              <li>
                <a href="help">
                  <span class="icon-help"></span>
                </a>
              </li>
            </ul>

          </section>
        </nav>
      <?php if ($top_bar_classes): ?>
      </div>
      <?php endif; ?>
      <!--/.top-bar -->
    <?php endif; ?>
  </header> <!--/.l-header -->

  <!-- NATURALIS header -->
  <?php if (  $is_front  ): ?>
    <!--.l-header-region -->
    <section class="l-header-region row show-for-medium-up <?php print $header_background; ?>" id="naturalis-header">

      <!--Prints the Naturalis logo. Only it's colors can be changed by means of admin > settings > appereance -->

      <div class="medium-2 columns" id="naturalis-logo">
        <img src="<?php print $naturalis_logo; ?>"/>
      </div>

      <div class="medium-6 columns" id="title-and-slogan">

        <?php if ($site_name): ?>
          <h1>
            <?php print $site_name; ?>
          </h1>
        <?php endif; ?>

        <?php if ($site_slogan): ?>
          <h2 title="<?php print $site_slogan; ?>" class="site-slogan"><?php print $site_slogan; ?></h2>
        <?php endif; ?>

        <div class="intro-more hidden">
          <i class="icon-double-chevron-down"></i>
          <?php print t('Read more'); ?>
        </div>

        <div id="intro">
            <?php print $intro; ?>
            <div class="intro-less ">
              <i class="icon-double-chevron-up"></i>
              <?php print t('Back'); ?>
            </div>
        </div>

      </div>




      <div class="medium-4 columns" id="logo"><!-- the photo is used as 'logo' -->
        <img src='<?php print $logo;?>'/>
      </div>

    </section>
    <!--/.l-header-region -->
  <?php endif; ?>

    <?php if (!empty($page['header'])): ?>
      <!--.l-header-region -->
      <section class="l-header-region row">
        <div class="large-12 columns">
          <?php print render($page['header']); ?>
        </div>
      </section>
      <!--/.l-header-region -->
    <?php endif; ?>



  <?php if (!empty($page['featured'])): ?>
    <!--/.featured -->
    <section class="l-featured row">
      <div class="large-12 columns">
        <?php print render($page['featured']); ?>
      </div>
    </section>
    <!--/.l-featured -->
  <?php endif; ?>

  <?php if ($messages && !$zurb_foundation_messages_modal): ?>
    <!--/.l-messages -->
    <section class="l-messages row">
      <div class="large-12 columns">
        <?php if ($messages): print $messages; endif; ?>
      </div>
    </section>
    <!--/.l-messages -->
  <?php endif; ?>

  <?php if (!empty($page['help'])): ?>
    <!--/.l-help -->
    <section class="l-help row">
      <div class="large-12 columns">
        <?php print render($page['help']); ?>
      </div>
    </section>
    <!--/.l-help -->
  <?php endif; ?>

  <main role="main" class="row l-main">
    <div class="<?php print $main_grid; ?> main columns">
      <?php if (!empty($page['highlighted'])): ?>
        <div class="highlight panel callout">
          <?php print render($page['highlighted']); ?>
        </div>
      <?php endif; ?>

      <a id="main-content"></a>

      <?php if ($title && !$is_front): ?>
        <?php print render($title_prefix); ?>
        <h1 id="page-title" class="title"><?php print $title; ?></h1>
        <?php print render($title_suffix); ?>
      <?php endif; ?>

      <?php if (!empty($tabs)): ?>
        <div class="tabs">
          <?php print render($tabs); ?>
          <?php if (!empty($tabs2)): print render($tabs2); endif; ?>
        </div>
      <?php endif; ?>

      <?php if ($action_links): ?>
        <ul class="action-links">
          <?php print render($action_links); ?>
        </ul>
      <?php endif; ?>

      <?php print render($page['content']); ?>
    </div>
    <!--/.main region -->

    <?php if (!empty($page['sidebar_first'])): ?>
      <aside role="complementary" class="<?php print $sidebar_first_grid; ?> sidebar-first columns sidebar">
        <?php print render($page['sidebar_first']); ?>
      </aside>
    <?php endif; ?>

    <?php if (!empty($page['sidebar_second'])): ?>
      <aside role="complementary" class="<?php print $sidebar_sec_grid; ?> sidebar-second columns sidebar">
        <?php print render($page['sidebar_second']); ?>
      </aside>
    <?php endif; ?>
  </main>
  <!--/.main-->

  <?php if (!empty($page['triptych_first']) || !empty($page['triptych_middle']) || !empty($page['triptych_last'])): ?>
    <!--.triptych-->
    <section class="l-triptych row">
      <div class="triptych-first large-4 columns">
        <?php print render($page['triptych_first']); ?>
      </div>
      <div class="triptych-middle large-4 columns">
        <?php print render($page['triptych_middle']); ?>
      </div>
      <div class="triptych-last large-4 columns">
        <?php print render($page['triptych_last']); ?>
      </div>
    </section>
    <!--/.triptych -->
  <?php endif; ?>

  <?php if (!empty($page['footer_firstcolumn']) || !empty($page['footer_secondcolumn']) || !empty($page['footer_thirdcolumn']) || !empty($page['footer_fourthcolumn'])): ?>

    <!--.footer-columns -->
    <section class="row l-footer-columns">
      <?php if (!empty($page['footer_firstcolumn'])): ?>
        <div class="footer-first large-3 columns">
          <?php print render($page['footer_firstcolumn']); ?>
        </div>
      <?php endif; ?>
      <?php if (!empty($page['footer_secondcolumn'])): ?>
        <div class="footer-second large-3 columns">
          <?php print render($page['footer_secondcolumn']); ?>
        </div>
      <?php endif; ?>
      <?php if (!empty($page['footer_thirdcolumn'])): ?>
        <div class="footer-third large-3 columns">
          <?php print render($page['footer_thirdcolumn']); ?>
        </div>
      <?php endif; ?>
      <?php if (!empty($page['footer_fourthcolumn'])): ?>
        <div class="footer-fourth large-3 columns">
          <?php print render($page['footer_fourthcolumn']); ?>
        </div>
      <?php endif; ?>
    </section>
    <!--/.footer-columns-->
  <?php endif; ?>

  <!-- .footer-->
  <?php if (!empty($page['footer'])): ?>
    <footer class="footer panel row" role="contentinfo">
      <div class="copyright large-12 columns">
        <?php print render($page['footer']); ?>
      </div>
    </footer>
  <?php endif; ?>
  <!--/.footer-->

  <!-- .bottom-bar-->
  <footer id="bottom-bar" role="contentinfo">

    <!-- #bottom-bar-top -->
    <?php if ($bottom_bar_top): ?>

      <div>
        <div class="row" id="bottom-bar-top">
          <?php if ($show_crumble && $breadcrumb): ?>
            <div class="medium-9 columns crumble">
              U bevindt zich hier:
              <?php print $breadcrumb; ?>
            </div>
          <?php endif; ?>

          <?php if ($show_links): ?>
            <div class="medium-3 columns external-links">
              <?php print $external_links_menu; ?>
            </div>
          <?php endif; ?>

        </div>
      </div>

    <?php endif; ?>
    <!-- /#bottom-bar-top -->

    <!-- #bottom-bar-bottom -->
    <?php if ($bottom_bar_bottom): ?>

      <div>
        <div class='row' id="bottom-bar-bottom">
          <?php if ($show_crumble): ?>
            <span class="copyright">
              &copy; Naturalis 2014
            </span>
          <?php endif; ?>

          <?php if ($show_service_menu): ?>
            <?php print $service_menu; ?>
          </span>
          <?php endif; ?>

        </div>
      </div>

    <?php endif; ?>
    <!-- /#bottom-bar-top -->

  </footer>
  <!-- / .bottom bar-->



  <?php if ($messages && $zurb_foundation_messages_modal): print $messages; endif; ?>

</div>


<!--/.page -->
