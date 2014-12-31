<?php

class ino_barcode {

 private $_text = null;
 private $_size = '30';
 private $_orientation = 'horizontal';
 private $_codeType = 'code128';
 private $_code_string = null;
 private $_specialWords = [
  "DEL" => "114113", "FNC 3" => "114311", "FNC 2" => "411113", "SHIFT" => "411311", "CODE C" => "113141", "FNC 4" => "114131", "CODE A" => "311141", "FNC 1" => "411131", "START A" => "211412", "START B" => "211214", "START C" => "211232", "STOP" => "2331112", "FNC 1" => '142112'
 ];

 public function setProperty($property, $value) {
  if (property_exists($this, $property)) {
   switch ($property) {
    case '_text':
     $this->$property = $value;
     break;

    case '_code_string':
     $this->_code_string = '';
     break;

    case '_group_by':
     $this->$property = is_array($value) ? $value : false;

    default:
     $this->$property = $value;
     break;
   }
  }
 }

 public $pageTitle = " ino Barcode  "; //page Title

 public function draw_barcode() {
  $this->_text = 'a';
  if (strtolower($this->_codeType) == "code128") {
   $chksum = 104;
   // Must not change order of array elements as the checksum depends on the array's key to validate final code
   $code_array = array(" " => "212222", "!" => "222122", "\"" => "222221", "#" => "121223", "$" => "121322", "%" => "131222", "&" => "122213", "'" => "122312", "(" => "132212", ")" => "221213", "*" => "221312", "+" => "231212", "," => "112232", "-" => "122132", "." => "122231", "/" => "113222", "0" => "123122", "1" => "123221", "2" => "223211", "3" => "221132", "4" => "221231", "5" => "213212", "6" => "223112", "7" => "312131", "8" => "311222", "9" => "321122", ":" => "321221", ";" => "312212", "<" => "322112", "=" => "322211", ">" => "212123", "?" => "212321", "@" => "232121", "A" => "111323", "B" => "131123", "C" => "131321", "D" => "112313", "E" => "132113", "F" => "132311", "G" => "211313", "H" => "231113", "I" => "231311", "J" => "112133", "K" => "112331", "L" => "132131", "M" => "113123", "N" => "113321", "O" => "133121", "P" => "313121", "Q" => "211331", "R" => "231131", "S" => "213113", "T" => "213311", "U" => "213131", "V" => "311123", "W" => "311321", "X" => "331121", "Y" => "312113", "Z" => "312311", "[" => "332111", "\\" => "314111", "]" => "221411", "^" => "431111", "_" => "111224", "\`" => "111422", "a" => "121124", "b" => "121421", "c" => "141122", "d" => "141221", "e" => "112214", "f" => "112412", "g" => "122114", "h" => "122411", "i" => "142112", "j" => "142211", "k" => "241211", "l" => "221114", "m" => "413111", "n" => "241112", "o" => "134111", "p" => "111242", "q" => "121142", "r" => "121241", "s" => "114212", "t" => "124112", "u" => "124211", "v" => "411212", "w" => "421112", "x" => "421211", "y" => "212141", "z" => "214121", "{" => "412121", "|" => "111143", "}" => "111341", "~" => "131141", "DEL" => "114113", "FNC 3" => "114311", "FNC 2" => "411113", "SHIFT" => "411311", "CODE C" => "113141", "FNC 4" => "114131", "CODE A" => "311141", "FNC 1" => "411131", "START A" => "211412", "START B" => "211214", "START C" => "211232", "STOP" => "2331112", "FNC 1" => '142112');
   $code_keys = array_keys($code_array);
   $code_values = array_flip($code_keys);
   $code_keys_specialWords = array_keys($this->_specialWords);
   $code_values_specialWords = array_flip($code_keys_specialWords);
   
    for ($X = 1; $X <= strlen($this->_text); $X++) {
    $spl_words = false;
    //check for special words
    $spl_Words = substr($this->_text, ($X - 1), 3);
    foreach ($code_keys_specialWords as $key_s) {
     if (strpos($key_s, $spl_Words)) {
      //a special word
      $spl_words = true;
      $this->_code_string .= $code_array[$key_s];
      $chksum = ($chksum + ($code_values_specialWords[$key_s] * $X));
      $key_s_len = strlen($key_s);
      echo '<br>'. $key_s_len. ' : ' . $X .'<br>' ;
      $X = $X + $key_s_len - 2;
      echo '<br>'.$this->_code_string;
      echo '<br>'.$key_s_len. ' : ' . $X .'<br>';
      break;
     }
    }
    if($spl_words){
     continue;
    }
    
     $activeKey = substr($this->_text, ($X - 1), 1);
     $this->_code_string .= $code_array[$activeKey];
     $chksum = ($chksum + ($code_values[$activeKey] * $X));
    echo '<br>'.$this->_code_string;
   }
   $this->_code_string .= $code_array[$code_keys[($chksum - (intval($chksum / 103) * 103))]];
   $this->_code_string = "211214" . $this->_code_string . "2331112";
  } elseif (strtolower($this->_codeType) == "code39") {
   $code_array = array("0" => "111221211", "1" => "211211112", "2" => "112211112", "3" => "212211111", "4" => "111221112", "5" => "211221111", "6" => "112221111", "7" => "111211212", "8" => "211211211", "9" => "112211211", "A" => "211112112", "B" => "112112112", "C" => "212112111", "D" => "111122112", "E" => "211122111", "F" => "112122111", "G" => "111112212", "H" => "211112211", "I" => "112112211", "J" => "111122211", "K" => "211111122", "L" => "112111122", "M" => "212111121", "N" => "111121122", "O" => "211121121", "P" => "112121121", "Q" => "111111222", "R" => "211111221", "S" => "112111221", "T" => "111121221", "U" => "221111112", "V" => "122111112", "W" => "222111111", "X" => "121121112", "Y" => "221121111", "Z" => "122121111", "-" => "121111212", "." => "221111211", " " => "122111211", "$" => "121212111", "/" => "121211121", "+" => "121112121", "%" => "111212121", "*" => "121121211");
   // Convert to uppercase
   $upper_text = strtoupper($this->_text);
   for ($X = 1; $X <= strlen($this->_text); $X++) {
    $this->_code_string .= $code_array[substr($upper_text, ($X - 1), 1)] . "1";
   }
   $this->_code_string = "1211212111" . $this->_code_string . "121121211";
  } elseif (strtolower($this->_codeType) == "code25") {
   $code_array1 = array("1", "2", "3", "4", "5", "6", "7", "8", "9", "0");
   $code_array2 = array("3-1-1-1-3", "1-3-1-1-3", "3-3-1-1-1", "1-1-3-1-3", "3-1-3-1-1", "1-3-3-1-1", "1-1-1-3-3", "3-1-1-3-1", "1-3-1-3-1", "1-1-3-3-1");
   for ($X = 1; $X <= strlen($this->_text); $X++) {
    for ($Y = 0; $Y < count($code_array1); $Y++) {
     if (substr($this->_text, ($X - 1), 1) == $code_array1[$Y]) {
      $temp[$X] = $code_array2[$Y];
     }
    }
   }
   for ($X = 1; $X <= strlen($this->_text); $X+=2) {
    if (isset($temp[$X]) && isset($temp[($X + 1)])) {
     $temp1 = explode("-", $temp[$X]);
     $temp2 = explode("-", $temp[($X + 1)]);
     for ($Y = 0; $Y < count($temp1); $Y++) {
      $this->_code_string .= $temp1[$Y] . $temp2[$Y];
     }
    }
   }
   $this->_code_string = "1111" . $this->_code_string . "311";
  } elseif (strtolower($this->_codeType) == "codabar") {
   $code_array1 = array("1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "$", ":", "/", ".", "+", "A", "B", "C", "D");
   $code_array2 = array("1111221", "1112112", "2211111", "1121121", "2111121", "1211112", "1211211", "1221111", "2112111", "1111122", "1112211", "1122111", "2111212", "2121112", "2121211", "1121212", "1122121", "1212112", "1112122", "1112221");
   // Convert to uppercase
   $upper_text = strtoupper($this->_text);
   for ($X = 1; $X <= strlen($upper_text); $X++) {
    for ($Y = 0; $Y < count($code_array1); $Y++) {
     if (substr($upper_text, ($X - 1), 1) == $code_array1[$Y]) {
      $this->_code_string .= $code_array2[$Y] . "1";
     }
    }
   }
   $this->_code_string = "11221211" . $this->_code_string . "1122121";
  }
  // Pad the edges of the barcode
  $code_length = 20;
  for ($i = 1; $i <= strlen($this->_code_string); $i++) {
   $code_length = $code_length + (integer) (substr($this->_code_string, ($i - 1), 1));
  }
  if (strtolower($this->_orientation) == "horizontal") {
   $img_width = $code_length;
   $img_height = $this->_size;
  } else {
   $img_width = $this->_size;
   $img_height = $code_length;
  }
  $image = imagecreate($img_width, $img_height);
  $black = imagecolorallocate($image, 0, 0, 0);
  $white = imagecolorallocate($image, 255, 255, 255);
  imagefill($image, 0, 0, $white);
  $location = 10;
  for ($position = 1; $position <= strlen($this->_code_string); $position++) {
   $cur_size = $location + ( substr($this->_code_string, ($position - 1), 1) );
   if (strtolower($this->_orientation) == "horizontal") {
    imagefilledrectangle($image, $location, 0, $cur_size, $img_height, ($position % 2 == 0 ? $white : $black));
   } else {
    imagefilledrectangle($image, 0, $location, $img_width, $cur_size, ($position % 2 == 0 ? $white : $black));
   }
   $location = $cur_size;
  }
  ob_start();
  imagepng($image);
  imagedestroy($image);
  $image_f = ob_get_contents();
  ob_end_clean();
  $image_data_base64 = base64_encode($image_f);
  echo '<img src="data:image/png;base64,' . $image_data_base64 . '" />';
  unset($image_data_base64);
  unset($image_f);
//  include __DIR__.'\barcode.php';
 }

}

//end of extn_contact class
?>