source_dir="./public_html"
target_dir="$HOME/public_html"

if [ -d "$source_dir" ]; then
  mkdir -p "$target_dir"
  cp -r "$source_dir"/* "$target_dir"
  echo "Directory and files merged successfully."
else
  echo "Source directory not found: $source_dir"
fi