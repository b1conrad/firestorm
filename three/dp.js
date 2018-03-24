function goEdit(theP,theSavedP) {
  for ( var f in theSavedP ) {
    theP[f].readOnly = false;
  }
  theP.Edit.disabled = true;
  theP.Save.disabled = false;
  theP.Cancel.disabled = false;
  return false;
}
function goBrowse(theP,theSavedP) {
  for ( var f in theSavedP ) {
    theP[f].readOnly = true;
  }
  theP.Edit.disabled = false;
  theP.Save.disabled = true;
  theP.Cancel.disabled = true;
}
function goCancel(theP,theSavedP) {
  for ( var f in theSavedP ) {
    theP[f].value = theSavedP[f];
  }
  goBrowse(theP,theSavedP);
  return false;
}
