function getNumbers(...ids) {
  return ids.map((id) =>
    document.getElementById(id).value != undefined
      ? Number(document.getElementById(id).value)
      : null,
  );
}

function isInvalid(...ids) {
  return ids
    .map((id) => document.getElementById(id).checkValidity())
    .some((v) => v === false);
}

function changeParagraph() {
  const ids = [
    'border_R',
    'border_G',
    'border_B',
    'border_width',
    'bg_R',
    'bg_G',
    'bg_B',
  ];

  if (isInvalid(...ids)) {
    return;
  }

  const [borderR, borderG, borderB, borderWidth, bgR, bgG, bgB] = getNumbers(
    ...ids,
  );

  const p = document.getElementById('paragraph');

  p.style = Object.entries({
    'border-color': `rgb(${borderR}, ${borderG}, ${borderB})`,
    'border-width': `${borderWidth}px`,
    'background-color': `rgb(${bgR}, ${bgG}, ${bgB})`,
  }).reduce((p, [k, v]) => p + `${k}: ${v};`, '');
}
