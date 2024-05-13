import numpy as np
import urllib.request
from PIL import Image
import json
from tqdm import tqdm
import labelbox as lb
from labelbox import Project, Dataset, Client, OntologyBuilder
import os

# ID project labelbox
PROJECT_ID = "clvggmnsa001907zf5j51g5sv"
DATASET_ID = "clvehmguz004y0759gbp6wgyt"
PROJECT_NAME = "Cell Analysis"
DATASET_NAME = "Cells"

TASK_ID = "clw4knr6k06ui0761d21xbpvb"

API_KEY = ''
client = Client(api_key=API_KEY)

project = client.get_project(PROJECT_ID)
# dataset = client.get_dataset(DATASET_ID)


# # Image export

# params = {
# 	"data_row_details": True,
# 	"metadata_fields": False,
# 	"attachments": False,
# 	"project_details": False,
# 	"performance_details": False,
# 	"label_details": True,
# 	"interpolated_frames": False
# }

# filters= {
#   "last_activity_at": ["2000-01-01 00:00:00", "2050-01-01 00:00:00"],
#   "workflow_status": "Done"
# }

# project = client.get_project(project_id=PROJECT_ID)
# export_task = project.export_v2(params=params, filters=filters)
# export_task.wait_till_done()

# if export_task.errors:
#   print(export_task.errors)

# export_json = export_task.result
# # print("results: ", export_json)
# export_json
    
#   
with open('coco_format.json', 'r') as f:
    coco = json.load(f)
    
    
# Assuming coco['images'] is loaded with appropriate data structure
# Define category names and their corresponding indexes
category_names = ['Eosinophil', 'Lymphocyte', 'Marcophage/Monocyte', 'Neutrophil', 'Unknown cell/Debris']
category_indexes = {name: idx for idx, name in enumerate(category_names)}

# Process each image in the dataset
# Assuming coco["images"] and client.headers are defined
output_dir = './Data/Masks/'
if not os.path.exists(output_dir):
    os.makedirs(output_dir)

for idx, image in enumerate(tqdm(coco["images"])):
    output_path = os.path.join(output_dir, 'mask_{}'.format(image['file_name']) + '.npy')

    # Check if the file already exists
    if not os.path.exists(output_path):
        combined_masks = np.zeros((1024, 1024, 5), dtype=np.uint8)  # Assuming all masks are the same size

        # Process each annotation in the image
        for annotation in image['annotations']:
            category_id = annotation['category_id']
            mask_url = annotation['mask']
            
            try:
                # Make the API request
                req = urllib.request.Request(mask_url, headers=client.headers)
                with urllib.request.urlopen(req) as response:
                    mask = Image.open(response)
                    mask_array = np.array(mask)
                    
                    # Assuming the masks are binary (255 where the mask is, 0 otherwise)
                    mask_array = (mask_array > 0).astype(np.uint8)  # Convert to binary mask if not already

                    # Add mask to the correct channel based on category_id
                    if 0 <= category_id < 5:  # Ensure the category_id is valid
                        combined_masks[:, :, category_id] += mask_array  # Stack the mask in the corresponding channel

            except Exception as e:
                print(f"Failed to process mask from {mask_url}: {e}")

        # Save the combined masks array as a NumPy file
        np.save(output_path, combined_masks)
    else:
        print(f"File {output_path} already exists, skipping.")
