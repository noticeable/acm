��[1,r)��Χ�ڲ���ֵv�������±�
����a�����Ѿ�����С��������
ʧ�ܷ���-1

int bs(int a[],int l,int h,int v)
{
	int m;
	while(l<h)
	{
		m=(l+h)>>1;
		if(a[m]==v)
		{
			return m;
		}
		if(a[m]<v)
		{
			l=m+1;
		}
		else
		{
			h=m;
		}
	}
	return -1;
}




���ڵ���v�ĵ�һ��ֵ
�����������l<=h
����ֵl���Ǻ����

int bs(int a[],int l,int h,int v)
{
	int m;
	while(l<h)
	{
		m=(l+h)>>1;
		if(a[m]<v)
		{
			l=m+1;
		}
		else
		{
			h=m;
		}
	}
	return l;
}