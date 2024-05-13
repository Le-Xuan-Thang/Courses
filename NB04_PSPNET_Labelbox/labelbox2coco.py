import json
import numpy as np
from tqdm import tqdm

# Function to convert numpy types to Python types for JSON serialization
def default_converter(obj):
    if isinstance(obj, np.integer):
        return int(obj)
    elif isinstance(obj, np.floating):
        return float(obj)
    elif isinstance(obj, np.ndarray):
        return obj.tolist()
    raise TypeError(f"Object of type {obj.__class__.__name__} is not JSON serializable")

# Load your exported JSON data
with open('/mnt/d/03_OneDrive/OneDrive/01_WORKING/Coursera/export_json.json', 'r') as file:
    data = json.load(file)

# Prepare the structures for COCO format
coco_format = {
    "images": []
}

# Helper to find index from category names
def find_index(category_names, name_to_check):
    matches = np.array(category_names) == name_to_check
    return int(np.argmax(matches)) if matches.any() else -1

# Define unique categories
category_names = ['Eosinophil', 'Lymphocyte', 'Marcophage/Monocyte', 'Neutrophil', 'Unknown cell/Debris']
category_names = np.unique(category_names)

# Process each entry
for entry in tqdm(data):
    image_info = {
        "file_name": entry['data_row']['external_id'],
        "height": entry['media_attributes']['height'],
        "width": entry['media_attributes']['width'],
        "id": entry['data_row']['id'],
        "annotations": [],
    }

    labels = entry['projects']['clvggmnsa001907zf5j51g5sv']['labels']
    for label in labels:
        objects = label['annotations']['objects']
        for obj in objects:
            index = find_index(category_names, obj['name'])
            obj_info = {
                "name": obj['name'],
                "category_id": index,
                "mask": obj['mask']['url'],
                "composite_mask": obj['composite_mask']['url'],
                
            }
            image_info['annotations'].append(obj_info)
    
    coco_format['images'].append(image_info)

# Save to a new JSON file
with open('coco_format.json', 'w') as f:
    json.dump(coco_format, f, default=default_converter, indent=4)

print("Conversion to COCO format completed.")
