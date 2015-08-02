<?xml version="1.0"?>

<?xml-stylesheet type="text/css" href="chrome://global/skin/" ?>
<?xml-stylesheet type="text/css"
href="chrome://xulschoolhello/skin/browserOverlay.css" ?>

<window
 id="dataEntryForm-window"
 title="Data Entry Form"
 flex = "1"
 resizable ="yes"
 orient="vertical"
 sizemode="normal"
 xmlns:html="http://www.w3.org/1999/xhtml"
 xmlns="http://www.mozilla.org/keymaster/gatekeeper/there.is.only.xul" >
 <!-- Other elements go here --> 
 <script type="application/x-javascript"
         src="chrome://xulschoolhello/content/jquery-2.0.3.min.js" />

 <script type="application/x-javascript"
         src="chrome://xulschoolhello/content/jquery-ui.min.js" />

 <script type="application/x-javascript"
         src="chrome://xulschoolhello/content/browserOverlay.js" />
 <vbox>
  <vbox flex="1">
   <hbox  min-width = "1000" align="start" flex="1">
    <toolbox>
     <toolbar id="findfiles-toolbar">
      <toolbarbutton id="newload"     class="tool-btn newload"     label="New"    accesskey="n" oncommand="XULSchoolChrome.BrowserOverlay.newLoad(event);"/>
      <toolbarbutton id="savfile"     class="tool-btn savefile"     label="Save"    accesskey="s" oncommand="XULSchoolChrome.BrowserOverlay.saveDataFile();"/>
      <toolbarbutton id="close"     class="tool-btn close"     label="Close"    accesskey="c" oncommand="window.close();"/>
     </toolbar>
    </toolbox>
   </hbox>
  </vbox>

  <vbox>
   <tabbox>
    <tabs>
     <tab label="Data Loader"/>
     <tab label="Commands"/>
     <tab label="Java Srcipt"/>
    </tabs>
    <tabpanels>
     <tabpanel id="data_loader">
      <vbox>
       <toolbox>
        <textbox multiline="true"  id="datatoupload" rows="30" cols="130" value="Enter | separated data here"/>
       </toolbox>
      </vbox>
      <vbox>
       <!--   <menulist label="Select Window" id="slect-window">
           <menupopup>
            <menuitem label="Dev" />
            <menuitem label="Production" />
           </menupopup>
          </menulist>-->
       <button id="start-load" label="Start Loading" accesskey="l" oncommand="XULSchoolChrome.BrowserOverlay.startDataLoading(event);"/>
      </vbox>
     </tabpanel>
     <tabpanel id="commands" style="overflow:scroll;">
      <grid flex="1">
       <columns>
        <column flex="1"/>
        <column flex="1"/>
        <column flex="2"/>
       </columns>
       <rows >
        <row class="heading">
         <description>String</description>
         <description>Command</description>
         <description>Example</description>
        </row>
        <row class="data-row">
         <description>TAB</description>
         <description>|</description>
         <description>111|ABC</description>
        </row>
        <row class="data-row">
         <description>Any Character</description>
         <description>The Character</description>
         <description>A B C</description>
        </row>
        <row class="data-row">
         <description>Shift + Character</description>
         <description>*S(Character)</description>
         <description>Shift + A  = *SA</description>
        </row>
        <row class="data-row">
         <description>Alt + Character</description>
         <description>*A(Character)</description>
         <description>Alt + A  = *AA</description>
        </row>
        <row class="data-row">
         <description>Shift + Character</description>
         <description>*S(Character)</description>
         <description>Shift + A  = *SA</description>
        </row>
        <row class="data-row">
         <description>Shift Ctrl + Character</description>
         <description>**SC(Character)</description>
         <description>Shift Ctrl + A  = **SCA</description>
        </row>
        <row class="data-row">
         <description>Alt Ctrl + Character</description>
         <description>**AC(Character)</description>
         <description>Alt Ctrl + A  = **ACA</description>
        </row>
        <row class="data-row">
         <description>Alt Shift + Character</description>
         <description>**AS(Character)</description>
         <description>Alt Shift + A  = **ASA</description>
        </row>
        <row class="data-row">
         <description>Up Arrow</description>
         <description>**UP</description>
         <description>**UP</description>
        </row>
        <row class="data-row">
         <description>Down Arrow</description>
         <description>**DOWN</description>
         <description>**DOWN</description>
        </row>
        <row class="data-row">
         <description>Left Arrow</description>
         <description>**LEFT</description>
         <description>**LEFT</description>
        </row>
        <row class="data-row">
         <description>Right Arrow</description>
         <description>**RIGHT</description>
         <description>**RIGHT</description>
        </row>
        <row class="data-row">
         <description>Enter/Return</description>
         <description>**ENTER</description>
         <description>**ENTER</description>
        </row>
        <row class="data-row">
         <description>Down Arrow</description>
         <description>**DOWN</description>
         <description>**DOWN*</description>
        </row>
        <row class="data-row">
         <description>Space Bar</description>
         <description>**SPACE</description>
         <description>**SPACE</description>
        </row>
        <row class="data-row">
         <description>Delete</description>
         <description>**DEL</description>
         <description>**DEL</description>
        </row>
        <row class="data-row">
         <description>Page Up Bar</description>
         <description>**PAGEUP</description>
         <description>**PAGEUP</description>
        </row>
        <row class="data-row">
         <description>Page Down</description>
         <description>**PAGEDOWN</description>
         <description>**PAGEDOWN</description>
        </row>
       </rows>
      </grid>
     </tabpanel>
     <tabpanel id="javascript">
      <toolbox>
       <textbox multiline="true"  id="user_javascript" rows="30" cols="150" value="Enter custom java script here"/>
      </toolbox>
     </tabpanel>
    </tabpanels>
   </tabbox>


  </vbox>
 </vbox>


</window>