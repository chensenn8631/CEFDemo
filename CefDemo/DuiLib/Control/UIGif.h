#pragma once
namespace DuiLib {
	class UILIB_API CGifUI : public CControlUI
	{
	public:
		CGifUI(void);
		~CGifUI(void);

		LPCTSTR	GetClass() const;
		LPVOID	GetInterface(LPCTSTR pstrName);
		void	DoInit() override;
		void	DoPaint(HDC hDC, const RECT& rcPaint) override;
		void	DoEvent(TEventUI& event) override;
		void	SetVisible(bool bVisible = true ) override;
		void	SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue) override;
		void	SetBkImage(LPCTSTR pStrImage);
		LPCTSTR GetBkImage();

		void	SetAutoPlay(bool bIsAuto = true );
		bool	IsAutoPlay() const;
		void	SetAutoSize(bool bIsAuto = true );
		bool	IsAutoSize() const;
		//����gifͼƬ
		void	PlayGif();
		//��ͣ������
		void	PauseGif();
		//��ͣ����
		void	StopGif();

	private:
		//��ʼ��gifͼƬ
		void	InitGifImage();
		//����gifͼƬ
		void	DeleteGif();
		//��Ӧ��ʱ��
		void    OnTimer( UINT_PTR idEvent );
		//����gifÿ֡
		void	DrawFrame( HDC hDC );
		//���ļ��ж�ȡgif�ļ����ڴ�
		Gdiplus::Image*	LoadGifFromFile(LPCTSTR pstrGifPath);
		//���ڴ��л�ȡ��gif�ļ�����
		Gdiplus::Image* LoadGifFromMemory( LPVOID pBuf,size_t dwSize );
	private:
		Gdiplus::Image	*m_pGifImage;				// gifͼƬ�洢
		UINT			m_nFrameCount;				// gifͼƬ��֡��
		UINT			m_nFramePosition;			// ��ǰ�ŵ��ڼ�֡
		Gdiplus::PropertyItem*	m_pPropertyItem;	// ֡��֮֡����ʱ��

		CDuiString		m_sBkImage;					// ͼƬ·��
		bool			m_bIsAutoPlay;				// �Ƿ��Զ�����gif
		bool			m_bIsAutoSize;				// �Ƿ��Զ�����ͼƬ���ô�С
		bool			m_bIsPlaying;				// ���ͼƬ�Ƿ��ڷ�ӳ
		ULONG_PTR		m_gdiplusToken;				// ��ʼ��gdi+�������ݴ���
		GdiplusStartupInput		m_gdiplusStartupInput;//gdi+��������Ϣ
	};
}

