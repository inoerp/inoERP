/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

var electron = require("electron");
var BrowserWindow = electron.BrowserWindow;
var app = electron.app;

app.on('ready', function(){
 var appWindow;
 appWindow = new BrowserWindow({
  width : 900,
  height: 700
 });
 
 appWindow.loadURL('file://' + __dirname + '/index.html');
 
});